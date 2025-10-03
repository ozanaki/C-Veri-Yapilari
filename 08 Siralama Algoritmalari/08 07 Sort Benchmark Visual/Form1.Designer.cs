namespace sorting
{
    partial class FormMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.button_fill = new System.Windows.Forms.Button();
            this.textBox_size = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button_insertion = new System.Windows.Forms.Button();
            this.button_selection = new System.Windows.Forms.Button();
            this.button_bubble = new System.Windows.Forms.Button();
            this.button_quick = new System.Windows.Forms.Button();
            this.button_merge = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.pictureBox1.Location = new System.Drawing.Point(25, 23);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(705, 289);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // button_fill
            // 
            this.button_fill.Location = new System.Drawing.Point(83, 325);
            this.button_fill.Name = "button_fill";
            this.button_fill.Size = new System.Drawing.Size(92, 37);
            this.button_fill.TabIndex = 2;
            this.button_fill.Text = "Dizi Oluştur";
            this.button_fill.UseVisualStyleBackColor = true;
            this.button_fill.Click += new System.EventHandler(this.button_fill_Click);
            // 
            // textBox_size
            // 
            this.textBox_size.Location = new System.Drawing.Point(25, 342);
            this.textBox_size.Name = "textBox_size";
            this.textBox_size.Size = new System.Drawing.Size(52, 20);
            this.textBox_size.TabIndex = 3;
            this.textBox_size.Text = "100";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(22, 326);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Veri Sayısı";
            // 
            // button_insertion
            // 
            this.button_insertion.Location = new System.Drawing.Point(194, 326);
            this.button_insertion.Name = "button_insertion";
            this.button_insertion.Size = new System.Drawing.Size(92, 37);
            this.button_insertion.TabIndex = 5;
            this.button_insertion.Text = "Insertion Sort";
            this.button_insertion.UseVisualStyleBackColor = true;
            this.button_insertion.Click += new System.EventHandler(this.button_insertion_Click);
            // 
            // button_selection
            // 
            this.button_selection.Location = new System.Drawing.Point(305, 325);
            this.button_selection.Name = "button_selection";
            this.button_selection.Size = new System.Drawing.Size(92, 37);
            this.button_selection.TabIndex = 6;
            this.button_selection.Text = "Selection Sort";
            this.button_selection.UseVisualStyleBackColor = true;
            this.button_selection.Click += new System.EventHandler(this.button_selection_Click);
            // 
            // button_bubble
            // 
            this.button_bubble.Location = new System.Drawing.Point(416, 325);
            this.button_bubble.Name = "button_bubble";
            this.button_bubble.Size = new System.Drawing.Size(92, 37);
            this.button_bubble.TabIndex = 7;
            this.button_bubble.Text = "Bubble Sort";
            this.button_bubble.UseVisualStyleBackColor = true;
            this.button_bubble.Click += new System.EventHandler(this.button_bubble_Click);
            // 
            // button_quick
            // 
            this.button_quick.Location = new System.Drawing.Point(527, 325);
            this.button_quick.Name = "button_quick";
            this.button_quick.Size = new System.Drawing.Size(92, 37);
            this.button_quick.TabIndex = 8;
            this.button_quick.Text = "Quick Sort";
            this.button_quick.UseVisualStyleBackColor = true;
            this.button_quick.Click += new System.EventHandler(this.button_quick_Click);
            // 
            // button_merge
            // 
            this.button_merge.Location = new System.Drawing.Point(638, 326);
            this.button_merge.Name = "button_merge";
            this.button_merge.Size = new System.Drawing.Size(92, 37);
            this.button_merge.TabIndex = 9;
            this.button_merge.Text = "Merge Sort";
            this.button_merge.UseVisualStyleBackColor = true;
            this.button_merge.Click += new System.EventHandler(this.button_merge_Click);
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(755, 391);
            this.Controls.Add(this.button_merge);
            this.Controls.Add(this.button_quick);
            this.Controls.Add(this.button_bubble);
            this.Controls.Add(this.button_selection);
            this.Controls.Add(this.button_insertion);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.textBox_size);
            this.Controls.Add(this.button_fill);
            this.Controls.Add(this.pictureBox1);
            this.Name = "FormMain";
            this.Text = "Sorting Algoritms";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button_fill;
        private System.Windows.Forms.TextBox textBox_size;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button_insertion;
        private System.Windows.Forms.Button button_selection;
        private System.Windows.Forms.Button button_bubble;
        private System.Windows.Forms.Button button_quick;
        private System.Windows.Forms.Button button_merge;
    }
}

