using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Hanoi
{
    class Disk
    {
        private char name;
        private Color color;
        private int height;
        private int width;

        public Disk(char DiskName, Color DiskColor, int Width, int Height)
        {
            name = DiskName;
            color = DiskColor;
            width = Width;
            height = Height;
        }

        public char Name { get { return name; }  }
        public Color Color { get { return color; }  }
        public int Width { get { return width; }  }
        public int Height { get { return height; } }
    }
}
