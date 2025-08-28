using System.Data.SqlTypes;
using System.Numerics;

namespace Program
{
    internal class Program
    {
        static void Main()
        {
            #region 단일 책임 원칙

            // 클래스의 구성 단위가 하나의 책임만 가질 수 있도록
            // 설계해야 되는 원칙

            //List<Quest> quests = new List<Quest>();
            //
            //Quest quest1 = new Quest("스킬 습득 훈련", "K키를 눌러 아무 스킬이나 습득 완료", new Reward(200, 5000, new int[] { }));
            //Quest quest2 = new Quest("기본 공격 훈련", "허수아비를 10번 타격", new Reward(150, 7500, new int[] {  }));
            //Quest quest3 = new Quest("기본 이동 훈련", "지정 지점 까지 1분 내에 주파", new Reward(250, 4000, new int[] {  }));
            //
            //quests.Add(quest1);
            //quests.Add(quest2);
            //quests.Add(quest3);
            //
            //foreach(var q  in quests)
            //{
            //    q.Describe();
            //}

            #endregion

            #region 개방 폐쇄 원칙

            // 소프트웨어의 구성 요소는 확장에는 열려 있어야 하고, 변경에는 닫혀 있어야 한다.
            // 버트란드 마이어(Bertrand Meyer)

            Enchant enchant = new Enchant();

            enchant.Enhance(new Item(1, 1, "sword", 30, 10, 0));
            enchant.Enhance(new Item(2, 2, "neckless", 0, 0, 20));
            enchant.Enhance(new Item(3, 3, "shoes", 10, 15, 0));

            #endregion
        }
    }
}
