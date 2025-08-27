using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal abstract class Terrain
    {
        protected int width;
        public int Width
        {
            get { return width; }
            set { width = value; }
        }
        protected int height;
        public int Height
        {
            get { return height; }
            set { height = value; }
        }

        public Terrain(int width, int height)
        {
            this.width = width;
            this.height = height;
        }

        public abstract void Activate();

        public abstract void Description();
        
    }

    internal class Cave : Terrain, ICoverable
    {
        public override void Activate() { }

        public Cave(int width, int height) : base(width, height) { }

        public override void Description()
        {
            Console.WriteLine("동굴이다.");
        }

        public void TakeCover()
        {
            Console.WriteLine("동굴 : 엄폐 가능");
        }
    }

    internal class Graveyard : Terrain, ICoverable
    {
        public Graveyard(int width, int height) : base(width,height) { }

        public override void Activate() { }

        public override void Description()
        {
            Console.WriteLine("묘지다.");
        }

        public void TakeCover()
        {
            Console.WriteLine("묘지 : 엄폐 가능");
        }
    }

    internal class Coast : Terrain, ITraversable
    {
        public Coast(int width, int height) : base (width,height) { }

        public override void Activate()
        {
            Console.WriteLine($"통과여부 : {Traverse()}");
        }

        public override void Description()
        {
            Console.WriteLine("해안지대다.");
        }

        public bool Traverse()
        {
            return true;
        }
    }
}
