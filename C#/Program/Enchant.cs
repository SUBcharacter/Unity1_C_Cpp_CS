using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal interface IEnchantable
    {
        public void Upgrade();

    }

    internal class Enchant
    {
        public void Enhance(Item item)
        {
            if (item is IEnchantable i)
            {
                i.Upgrade();
            }
            else
                return;
        }
    }

}
