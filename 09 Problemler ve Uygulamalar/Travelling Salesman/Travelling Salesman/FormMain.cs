using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Travelling_Salesman
{
    public partial class FormMain : Form
    {
        private List<Node> nodes;
        private List<Link> links;
        private Point mousedown;
        private Node beginnode;
        private Node endnode;
        private Point mouseup;
        private bool drawlink;
        private bool movenode;
        private int nextindex;

        public FormMain()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            nodes = new List<Node>();
            links = new List<Link>();
            nextindex = 0;
        }

        private string GenerateName(int index)
        {
            int utf = Char.ConvertToUtf32("A", 0);
            return Char.ConvertFromUtf32(utf + index);
        }

        private Node GetPointNode(Point p)
        {
            foreach (Node n in nodes)
            {
                if (n.IsMyPoint(p)) return n;
            }
            return null;
        }

        private void DrawNodes()
        {
            Bitmap bmp = new Bitmap(pictureBox1.Width,pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);

            // Çizim alanını komple temizle
            g.Clear(Color.White);

            // Düğümleri çiz
            foreach (Node n in nodes)
            {
                if(n.Selected) g.DrawEllipse(new Pen(new SolidBrush(Color.Red),3), n.Rectangle);
                else g.DrawEllipse(new Pen(new SolidBrush(Color.Red), 2), n.Rectangle);
                g.DrawString(n.Name,SystemFonts.CaptionFont,new SolidBrush(Color.Red),
                    new Point(n.Rectangle.X+n.Rectangle.Width,n.Rectangle.Y+n.Rectangle.Height));
            }
            // Bağlantıları çiz
            foreach (Link l in links)
            {
                int x1 = l.Node1.Location.X;
                int y1 = l.Node1.Location.Y;
                int x2 = l.Node2.Location.X;
                int y2 = l.Node2.Location.Y;
                if(l.Selected) g.DrawLine(new Pen(new SolidBrush(Color.Blue), 3), l.Node1.Location, l.Node2.Location);
                else g.DrawLine(new Pen(new SolidBrush(Color.Blue), 2), l.Node1.Location, l.Node2.Location);
                int dist = (int)Math.Sqrt(Math.Pow(Math.Abs(x1 - x2), 2) + Math.Pow(Math.Abs(y1 - y2), 2));
                SizeF size = g.MeasureString(dist.ToString(), SystemFonts.CaptionFont);
                Point textpos=new Point(x1 < x2 ? x1 + (x2 - x1) / 2 : x2 + (x1 - x2) / 2, y1 < y2 ? y1 + (y2 - y1) / 2 : y2 + (y1 - y2) / 2);
                g.FillRectangle(new SolidBrush(Color.Blue), textpos.X, textpos.Y, size.Width, size.Height);
                g.DrawString(dist.ToString(), SystemFonts.CaptionFont, new SolidBrush(Color.White),textpos);
            }

            pictureBox1.Image = bmp;
            g.Dispose();
        }

        private void ListLinks()
        {
            listBox1.BeginUpdate();
            listBox1.Items.Clear();
            foreach (Link l in links)
            {
                listBox1.Items.Add(
                    String.Format("{0}. {1} - {2} - {3}",
                    listBox1.Items.Count,l.Node1.Name,l.Cost,l.Node2.Name));
            }
            listBox1.EndUpdate();
        }

        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            mousedown = e.Location;
            beginnode = GetPointNode(e.Location);

            if(e.Button==MouseButtons.Left)
            {
                foreach (Node n in nodes) n.Selected = false; 
                if (beginnode == null)
                {
                    // mevcut noktada yoksa yeni node ekle
                    nodes.Add(new Node(GenerateName(nextindex++), e.Location));
                }
                else
                {
                    // eğer mevcut yerde node varsa bağlantı çiz
                    beginnode.Selected = true;                    
                    drawlink = true;
                    //movenode = true;
                }
            }
            else if (e.Button == MouseButtons.Right)
            {
                if (beginnode != null)
                {
                    nodes.Remove(beginnode);
                    List<Link> removes = new List<Link>();
                    foreach (Link l in links)
                    {
                        if (l.Node1 == beginnode || l.Node2 == beginnode)
                        {
                            removes.Add(l);
                        }
                    }
                    foreach (Link l in removes)
                    {
                        links.Remove(l);
                    }
                }
            }
            DrawNodes();
            ListLinks();
        }

        private void pictureBox1_MouseUp(object sender, MouseEventArgs e)
        {
            if(e.Button==MouseButtons.Left)
            {
                mouseup = e.Location;
                if (drawlink)
                {
                    drawlink = false;
                    endnode = GetPointNode(e.Location);
                    if (beginnode != null && endnode != null && beginnode!=endnode)
                    {
                        foreach (Link l in links) l.Selected = false;
                        int x1 = beginnode.Location.X;
                        int y1 = beginnode.Location.Y;
                        int x2 = endnode.Location.X;
                        int y2 = endnode.Location.Y;
                        int dist = (int)Math.Sqrt(Math.Pow(Math.Abs(x1 - x2), 2) +
                                        Math.Pow(Math.Abs(y1 - y2), 2));
                        links.Add(new Link(beginnode, endnode, dist));
                    }
                    //nodes[selectedindex].Location = e.Location;
                }                
            }

            drawlink = false;
            movenode = false;

            DrawNodes();
            ListLinks();
        }

        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                if (drawlink)
                {
                    pictureBox1.Refresh();
                    int x1 = mousedown.X;
                    int y1 = mousedown.Y;
                    int x2 = e.Location.X;
                    int y2 = e.Location.Y;
                    Graphics g = Graphics.FromHwnd(pictureBox1.Handle);
                    g.DrawLine(new Pen(new SolidBrush(Color.Blue),2), mousedown, e.Location);
                    int dist = (int)Math.Sqrt(Math.Pow(Math.Abs(x1-x2),2) + Math.Pow(Math.Abs(y1-y2),2));
                    g.DrawString(dist.ToString(), SystemFonts.CaptionFont, new SolidBrush(Color.Blue),
                        new Point(x1<x2?x1+(x2-x1)/2:x2+(x1-x2)/2,y1<y2?y1+(y2-y1)/2:y2+(y1-y2)/2));
                    g.Dispose();
                }
                else if (movenode)
                {
                    beginnode.Location = e.Location;
                    DrawNodes();
                    pictureBox1.Refresh();
                }
            }
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            foreach (Link l in links) l.Selected = false;
            links[listBox1.SelectedIndex].Selected = true;
            DrawNodes();
        }

        private int Distance(Node Node1, Node Node2)
        {
            if (Node1 == Node2) return 0;

            foreach (Link l in links)
            {
                if((l.Node1==Node1 && l.Node2==Node2) ||
                   (l.Node1 == Node2 && l.Node2 == Node1))
                {
                    return l.Cost;
                }
            }

            return -1;
        }

        private int PathDistance(List<Node> Nodes)
        {
            int dist = 0;
            for(int i=0; i<Nodes.Count-1; i++)
            {
                int temp = Distance(Nodes[i], Nodes[i + 1]);
                if (temp < 0) return -1;
                dist += temp;
            }
            return dist;
        }

        private Node NearestNeighbor(Node Node)
        {
            int min = int.MaxValue;
            Node n = null;
            foreach (Link l in links)
            {
                if (l.Node1 == Node || l.Node2 == Node)
                {
                    if (l.Cost < min) 
                    {
                        min = l.Cost;
                        if(l.Node1==Node) n=l.Node2;
                        else if(l.Node2==Node) n=l.Node1;
                    }
                }
            }

            if (min > 0)
            {
                return n;
            }

            return null;
        }
        /*
        void Dijkstra(char basla)
        {
	        char tmp[16], ok[N]={0};
	        int i,j,ead,ek;
	
	        if(basla<'A' || basla>='A'+N) return;
		
	        for(i=0; i<N; ++i)
		        for(j=0; j<N; ++j)		
			        rota[i][j]=0;

	        for(i=0; i<N; ++i) ekm[i]=INT_MAX;
	        ead=basla-'A';
	        ekm[ead]=0;
		
	        for(i=0; i<N; ++i)
	        {
		        for(j=0; j<N; ++j)
		        {
			        if(!ok[j])
			        {
				        if(graf[ead][j]>0)
				        {
					        if(ekm[j]>graf[ead][j]+ekm[ead])
					        {
						        ekm[j]=graf[ead][j]+ekm[ead];
						        strcpy(rota[j],rota[ead]);
						        sprintf(tmp,"%c->",'A'+ead);
						        strcat(rota[j],tmp);
					        }
				        }
			        }
		        }
		        ek=INT_MAX;
		        for(j=0; j<N; j++)
		        {
			        if(!ok[j])
			        {
				        if(ekm[j]<ek)
				        {
					        ek=ekm[j];
					        ead=j;
				        }
			        }
		        }
		        ok[ead]=1;
	        }
	        for(i=0; i<N; ++i)
	        {
		        sprintf(tmp,"%c",'A'+i);
		        strcat(rota[i],tmp);
	        }
        }

        void git(char basla, char hedef)
        {
            if (basla < 'A' || basla >= 'A' + N) return;
            if (hedef < 'A' || hedef >= 'A' + N) return;

            Dijkstra(basla);

            printf("En kisa rota: %s\n", rota[hedef - 'A']);
            printf("En kisa rota maliyeti: %d\n", ekm[hedef - 'A']);
        }
        */

        private void button_hamilton_Click(object sender, EventArgs e)
        {
            Node begin=null, end=null;
            int bi = comboBox1.SelectedIndex;
            int ei = comboBox2.SelectedIndex;

            if (bi >= 0) begin = nodes[bi];
            if (ei >= 0) end = nodes[ei];

            if ((begin==null) || (end==null))
            {
                MessageBox.Show("Lütfen Nereden Nereye gidileceğiniz seçiniz.", "Eksik Bilgi", MessageBoxButtons.OK);
                return;
            }

            textBox1.Clear();

            // En yakın komşu algoritması
            List<Node> path = new List<Node>();

            path.Clear();
            path.Add(begin);

            int i, j;
            int next = bi;
            bool finished = false;
            do
            {

                int ind = -1;
                int min = int.MaxValue;
                for (i = 0; i < nodes.Count; i++)
                {
                    // aynı noktadan tekrar geçme
                    if (path.Contains(nodes[i])) continue;

                    // yol boyunca toplam mesafeyi hesapla
                    int dist = 0;
                    for (j = 0; j < path.Count - 1; j++)
                    {
                        dist += Distance(path[j], path[j + 1]);
                    }

                    // yeni düğümle birlikte en mesafeyi hesapla
                    int distnext = Distance(path[path.Count-1], nodes[i]);
                    if (distnext <= 0) continue;

                    // en kısa mesafeyi bul
                    if (dist+distnext < min)
                    {
                        min = dist+distnext;
                        ind = i;
                    }
                }

                if (ind >= 0)
                {
                    // bulunan düğümü yola ekle
                    path.Add(nodes[ind]);
                    next = ind;

                    if (ind == ei)
                    {
                        // ekrana yaz
                        string s = "";
                        foreach (Node n in path)
                        {
                            s += n.Name + " > ";
                        }
                        textBox1.Text += s + Environment.NewLine;
                        Application.DoEvents();

                        finished = true;
                    }
                }

            } while(!finished);

            //textBox1.Text += path + Environment.NewLine;
        }

        private void button_close_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void comboBox1_DropDown(object sender, EventArgs e)
        {
            int index = comboBox1.SelectedIndex;
            comboBox1.Items.Clear();
            foreach (Node n in nodes) comboBox1.Items.Add(n.Name);
            if (index < comboBox1.Items.Count) comboBox1.SelectedIndex = index;
            else comboBox1.SelectedIndex = comboBox1.Items.Count - 1; 
        }

        private void comboBox2_DropDown(object sender, EventArgs e)
        {
            int index = comboBox2.SelectedIndex;
            comboBox2.Items.Clear();
            foreach (Node n in nodes) comboBox2.Items.Add(n.Name);
            if (index < comboBox2.Items.Count) comboBox2.SelectedIndex = index;
            else comboBox2.SelectedIndex = comboBox2.Items.Count - 1; 

        }


    }
}
