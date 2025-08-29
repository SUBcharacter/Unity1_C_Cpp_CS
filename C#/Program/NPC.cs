using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal abstract class NPC
    {
        protected int stat;

        public NPC(int s)
        {
            stat = s;
        }

        public abstract void Update();
    }

    internal class Merchant : NPC, ITradeable
    {
        public Merchant(int s) : base(s) {}

        public override void Update()
        {
            Trade();
        }

        public void Trade()
        {
            Console.WriteLine("거래 가능");
        }
    }

    internal class Princess : NPC , IMoveable
    {
        public Princess(int s) : base(s) { }

        public override void Update()
        {
            Move();
        }

        public void Move()
        {
            Console.WriteLine("공주 움직임");
        }
    }

    internal class Mercenary : NPC, IMoveable, IAttackable
    {
        public Mercenary(int s) : base (s) { }

        public override void Update()
        {
            Move();
            Attack();
        }

        public void Move()
        {
            Console.WriteLine("용병 움직임");
        }

        public void Attack()
        {
            Console.WriteLine("용병 공격");
        }
    }
}
