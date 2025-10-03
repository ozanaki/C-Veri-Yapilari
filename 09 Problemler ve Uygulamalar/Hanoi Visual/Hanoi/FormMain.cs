using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Hanoi
{
    public partial class FormMain : Form
    {
        // her bir çubuk, stack veri modeli ile temsil ediliyor
        private Stack<Disk> A, B, C;
        
        // disk sayısı
        private int disk_count;

        // Özyinelemeli çözüm fonksiyonunu geçici olarak durdurmak için
        private bool step;

        // Çözümde kullanılan hareket sayısı
        private int move_count;

        public FormMain()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            pictureBox1.Image = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            pictureBox2.Image = new Bitmap(pictureBox2.Width, pictureBox2.Height);
            pictureBox3.Image = new Bitmap(pictureBox3.Width, pictureBox3.Height);
            draw_disks(pictureBox1.Image, null);
            draw_disks(pictureBox2.Image, null);
            draw_disks(pictureBox3.Image, null);

        }

        private Color get_disk_color(char diskname)
        {
            switch (diskname)
            {
                case 'A': return Color.Blue;
                case 'B': return Color.Red;
                case 'C': return Color.Green;
                case 'D': return Color.Fuchsia;
                case 'E': return Color.Orange;
                case 'F': return Color.Navy;
                case 'G': return Color.Maroon;
                case 'H': return Color.Tomato;
                case 'I': return Color.Violet;
                case 'J': return Color.Magenta;
                case 'K': return Color.Linen;
                case 'L': return Color.Khaki;
                case 'M': return Color.Lavender;
                case 'N': return Color.Turquoise;
                case 'O': return Color.Thistle;
                case 'P': return Color.LightSalmon;
                case 'Q': return Color.SlateBlue;
                case 'R': return Color.Pink;
                case 'S': return Color.Purple;
                case 'T': return Color.Peru;
                case 'U': return Color.Gold;
                case 'V': return Color.Indigo;
                case 'W': return Color.MediumVioletRed;
                case 'X': return Color.Lime;
                case 'Y': return Color.LawnGreen;
                case 'Z': return Color.DarkTurquoise;
                default: return Color.Black;
            }
        }

        private void draw_disks(Image im, Disk[] disks)
        {
            Graphics g = Graphics.FromImage(im);
            g.Clear(Color.FromKnownColor(KnownColor.Control));

            Rectangle rect = new Rectangle(0, 0, im.Width, im.Height);
            Rectangle bar = new Rectangle((rect.Width-10)/2,rect.Y,10,rect.Height);
            Rectangle bottom = new Rectangle(rect.X, rect.Height - 10, rect.Width, 10);

            g.FillRectangle(new SolidBrush(Color.Black), bar);
            g.FillRectangle(new SolidBrush(Color.Black), bottom);

            if(disks!=null && disks.Length>0)
            {
                int y = im.Height - 11;
                for (int i = disks.Length-1; i >=0; i--)
                {
                    int x = (im.Width - disks[i].Width) / 2;
                    y -= disks[i].Height+1;
                    Rectangle r = new Rectangle(x, y, disks[i].Width, disks[i].Height);
                    g.FillRectangle(new SolidBrush(disks[i].Color), r);
                }
            }

            g.Dispose();

        }

        private void show_disks()
        {
            draw_disks(pictureBox1.Image, A.ToArray());
            draw_disks(pictureBox2.Image, B.ToArray());
            draw_disks(pictureBox3.Image, C.ToArray());
            pictureBox1.Refresh();
            pictureBox2.Refresh();
            pictureBox3.Refresh();
        }

        private void button_create_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            step = false;
            
            move_count = 0;
            disk_count = (int)numericUpDown1.Value;

            A = new Stack<Disk>(disk_count);
            B = new Stack<Disk>(disk_count);
            C = new Stack<Disk>(disk_count);

            A.Clear();
            B.Clear();
            C.Clear();
            listBox_steps.Items.Clear();

            int h = ((pictureBox1.Height - 10) - disk_count) / disk_count;
            if (h > 10) h = 10;
            int dw = pictureBox1.Width / (2 * disk_count);
            int w = pictureBox1.Width;
            for (int i = 0; i < disk_count; i++)
            {
                int utf = Char.ConvertToUtf32("A", 0);
                utf += disk_count - i - 1;
                char name = Char.ConvertFromUtf32(utf)[0];
                Color c = get_disk_color(name);
                Disk d = new Disk(name, c, w, h);
                A.Push(d);
                w -= 2 * dw;
            }

            show_disks();

            button_create.Enabled = false;
            numericUpDown1.Enabled = false;
            
            hanoi(disk_count, A, B, C);
            
            button_create.Enabled = true;
            numericUpDown1.Enabled = true;
        }

        private void hanoi(int DiskCount, Stack<Disk> From, Stack<Disk> Temp, Stack<Disk> To)
        {
            if (DiskCount == 1)
            {
                // sonraki adım için bekle
                while (!step) Application.DoEvents(); 

                //Move disc 1 from From to To;
                Disk D = From.Pop();
                To.Push(D);

                move_count++;
                listBox_steps.Items.Add(String.Format("{0}. {1}",move_count,D.Name));
                listBox_steps.SelectedIndex = listBox_steps.Items.Count - 1;

                show_disks();
                step = false;
                return;
            }
            else
            {
                hanoi(DiskCount - 1, From, To, Temp);
                hanoi(1, From, Temp, To);
                hanoi(DiskCount - 1, Temp, From, To);
            }
        }

        private void button_step_Click(object sender, EventArgs e)
        {
            timer1.Stop();
            step = true;
        }

        private void button_solve_Click(object sender, EventArgs e)
        {
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            step = true;
        }

        private void button_close_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            timer1.Interval = 50+trackBar1.Maximum-trackBar1.Value;
        }

    }
}
