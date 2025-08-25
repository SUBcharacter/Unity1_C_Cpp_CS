using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
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
    }
}
