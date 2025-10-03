using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Travelling_Salesman
{
    class Link
    {
        private int cost;
        private Node node1;
        private Node node2;
        private bool selected;

        public Link(Node Node1, Node Node2, int Cost)
        {
            node1 = Node1;
            node2 = Node2;
            cost = Cost;
            selected = true;
        }

        public Node Node1 { get { return node1; } }
        public Node Node2 { get { return node2; } }
        public int Cost { get { return cost; } }
        public bool Selected { get { return selected; } set { selected = value; } }
    }
}
