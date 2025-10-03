using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Travelling_Salesman
{
    class Node
    {
        private string name;
        private Point location;
        private const int width = 20;
        private const int height = 20;
        private Rectangle rect;
        private bool selected;


        public Node(string Name, Point Location)
        {
            name = Name;
            location = Location;
            rect = new Rectangle(location.X-width/2,location.Y-height/2,width,height);
            selected = true;
        }

        public string Name { get { return name; } }
        public Point Location { get { return location; } set { location = value; } }
        public Rectangle Rectangle { get { return rect; } }
        public bool Selected { get { return selected; } set { selected = value; } }
        public bool IsMyPoint(Point Point)
        {
            return rect.Contains(Point);
        }
    }
}
