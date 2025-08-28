using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal class Reward
    {
        Service service;
        public int exp;
        public int gold;
        public List<int> itemIdx;

        public Reward(int exp, int gold, int[] index)
        {
            this.exp = exp;
            this.gold = gold;
            itemIdx = new List<int>();

            for(int i = 0; i < index.Length; i++)
            {
                itemIdx.Add(index[i]);
            }
        }

        public void Describe()
        {
            Console.WriteLine($"경험치 : {exp}");
            Console.WriteLine($"골드 : {gold}\n");
            foreach(var i in itemIdx)
            {
                Console.WriteLine($"아이템 : {service.item[i]}");
            }
        }
    }
}
