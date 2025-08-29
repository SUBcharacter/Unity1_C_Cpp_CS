using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal abstract class Item
    {
        protected int id;
        protected int type;  // 1검, 2목걸이, 3신발
        protected string name;
        protected int str;
        protected int dex;
        protected int intel;

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

        public void PrintStat()
        {
            Console.WriteLine($"Name : {name}");
            Console.WriteLine($"STR : {str}");
            Console.WriteLine($"DEX : {dex}");
            Console.WriteLine($"INT : {intel}\n");
            
        }
    }

    internal class Sword : Item, IEnchantable
    {
        public Sword(int id, int type, string name, int str, int dex, int intel) : base(id, type, name, str, dex, intel)
        {
        }

        public void Upgrade()
        {
            str += (int)((float)str * 0.1f);
        }
    }

    internal class Neckless : Item, IEnchantable
    {
        public Neckless(int id, int type, string name, int str, int dex, int intel) : base(id, type, name, str, dex, intel)
        {
        }

        public void Upgrade()
        {
            intel += (int)((float)intel * 0.1f);
        }
    }

    internal class Shoes : Item, IEnchantable
    {
        public Shoes(int id, int type, string name, int str, int dex, int intel) : base(id, type, name, str, dex, intel)
        {
        }

        public void Upgrade()
        {
            dex += (int)((float)dex * 0.1f);
        }
    }


}
