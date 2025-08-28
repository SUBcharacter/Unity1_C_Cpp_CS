using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal class Item
    {
        private int id;
        private int type;  // 1검, 2목걸이, 3신발
        private string name;
        private int str;
        private int dex;
        private int intel;

        public int Id { get { return id; } }
        public int Type { get { return type; } }
        public string Name { get { return name; } }
        public int Str { get { return str; } set { str = value; } }
        public int Dex { get { return dex; } set { dex = value; } }
        public int Intel { get { return intel; } set { intel = value; } }

        public Item(int id, int type, string name, int str, int dex, int intel)
        {
            this.id = id;
            this.type = type;
            this.name = name;
            this.str = str;
            this.dex = dex;
            this.intel = intel;
        }

    }
}
