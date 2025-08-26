using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Grammer
{
    struct Vector2
    {
        public int x;
        public int y;

        public Vector2(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }

    internal class Utility
    {
        private int data;

        public void Pause()
        {
            Console.WriteLine("PAUSE");
        }

        public void Swap(ref int x, ref int y)
        {
            int temp = x;
            x = y;
            y = temp;
        }

        public void Absolute(in int value)
        {
            if(value >= 0 )
            {
                Console.WriteLine($"ABS : {value}");
            }
            else
            {
                Console.WriteLine($"ABS : {-value}");
            }

        }

        public void Magnitude(Vector2 value, out float length)
        {
            length = (float)Math.Sqrt(value.x * value.x + value.y * value.y);
        }
    }
}
