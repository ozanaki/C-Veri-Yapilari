using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace sorting
{
    public partial class FormMain : Form
    {
        private int[] dizi;

        public FormMain()
        {
            InitializeComponent();
        }

        private void show_data()
        {
            if (dizi == null) return;

            Bitmap bmp = new Bitmap(pictureBox1.Width, pictureBox1.Height);
            Graphics g = Graphics.FromImage(bmp);
            g.Clear(Color.White);

            int x, y, w, h;
            x = 0;
            y = 0;
            w = (bmp.Width-dizi.Length) / dizi.Length;
            if (w == 0) w = 1;

            for (int i = 0; i < dizi.Length; i++)
            {
                h = dizi[i];
                y = bmp.Height - h;
                Rectangle rect = new Rectangle(x,y,w,h);
                g.FillRectangle(new SolidBrush(Color.FromArgb(dizi[i]*0x0f0a0305)), rect);
                x += w;
                x++;
            }
            pictureBox1.Image = bmp;
            Application.DoEvents();
            System.Threading.Thread.Sleep(100);
        }

        private void button_fill_Click(object sender, EventArgs e)
        {
            try
            {
                int size = int.Parse(textBox_size.Text);

                dizi = new int[size];

                Random r = new Random(DateTime.Now.Millisecond);

                for (int i = 0; i < size; i++)
                {
                    dizi[i] = r.Next(0, pictureBox1.Height);
                }

                show_data();

            }
            catch (System.Exception ex)
            {
                ToolTip t = new ToolTip();
                t.Show("Lütfen geçerli bir tam say değeri giriniz.",textBox_size,3000);
            }

        }

        private void insertion_sort(int[] a, int n)
        {
            int k;
            for (k = 1; k < n; k++)
            {
                int key = a[k];
                int i = k - 1;
                while ((i >= 0) && (key < a[i]))
                {
                    a[i + 1] = a[i];
                    i--;
                }
                a[i + 1] = key;
                show_data();
            }
        }

        private void selection_sort(int[] p, int size)
        {
            int i, j, temp, min;

            for (i = 0; i < size - 1; i++)
            {
                min = i;
                for (j = i + 1; j < size; j++)
                {
                    if (p[min] > p[j]) min = j;
                }
                temp = p[min];
                p[min] = p[i];
                p[i] = temp;
                show_data();
            }
        }

        private void bubble_sort(int[] numbers, int array_size)
        {
            int i, j, temp;

            for (i = (array_size - 1); i > 0; i--)
            {
                for (j = 1; j <= i; j++)
                {
                    if (numbers[j - 1] > numbers[j])
                    {
                        temp = numbers[j - 1];
                        numbers[j - 1] = numbers[j];
                        numbers[j] = temp;
                    }
                    show_data();
                }
            }
        }

        private void quick_sort(int[] x, int first, int last)
        {
            int pivot, j, temp, i;

            if (first < last)
            {
                pivot = first;
                i = first;
                j = last;

                while (i < j)
                {
                    while (x[i] <= x[pivot] && i < last) i++;
                    while (x[j] > x[pivot]) j--;
                    if (i < j)
                    {
                        temp = x[i];
                        x[i] = x[j];
                        x[j] = temp;
                    }
                    show_data();
                }

                temp = x[pivot];
                x[pivot] = x[j];
                x[j] = temp;
                quick_sort(x, first, j - 1);
                quick_sort(x, j + 1, last);
            }
        }

        void merge(int[] numbers, int left, int mid, int right)
        {
            int i, left_end, num_elements, tmp_pos;
            int[] temp;

            left_end = mid - 1;
            tmp_pos = left;
            num_elements = right - left + 1;

            temp = new int[(left + num_elements)];

            while ((left <= left_end) && (mid <= right))
            {
                if (numbers[left] <= numbers[mid])
                {
                    temp[tmp_pos] = numbers[left];
                    tmp_pos = tmp_pos + 1;
                    left = left + 1;
                }
                else
                {
                    temp[tmp_pos] = numbers[mid];
                    tmp_pos = tmp_pos + 1;
                    mid = mid + 1;
                }
                show_data();
            }

            while (left <= left_end)
            {
                temp[tmp_pos] = numbers[left];
                left = left + 1;
                tmp_pos = tmp_pos + 1;
                show_data();
            }
            while (mid <= right)
            {
                temp[tmp_pos] = numbers[mid];
                mid = mid + 1;
                tmp_pos = tmp_pos + 1;
                show_data();
            }

            for (i = 0; i < num_elements; i++)
            {
                numbers[right] = temp[right];
                right = right - 1;
                show_data();
            }
        }

        void merge_sort(int[] numbers, int left, int right)
        {
            int mid;

            if (right > left)
            {
                mid = (right + left) / 2;
                merge_sort(numbers, left, mid);
                merge_sort(numbers, mid + 1, right);

                merge(numbers, left, mid + 1, right);
            }
        }

        private void button_insertion_Click(object sender, EventArgs e)
        {
            insertion_sort(dizi, dizi.Length);
        }

        private void button_selection_Click(object sender, EventArgs e)
        {
            selection_sort(dizi, dizi.Length);
        }

        private void button_bubble_Click(object sender, EventArgs e)
        {
            bubble_sort(dizi, dizi.Length);
        }

        private void button_quick_Click(object sender, EventArgs e)
        {
            quick_sort(dizi, 0, dizi.Length - 1);
        }

        private void button_merge_Click(object sender, EventArgs e)
        {
            merge_sort(dizi, 0, dizi.Length - 1);
        }


    }
}
