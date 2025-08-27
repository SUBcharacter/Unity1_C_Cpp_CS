using System.Data.SqlTypes;
using System.Numerics;

namespace Program
{
    

    internal class Program
    {
        static void Main()
        {
            #region 추상 클래스

            // 직접 생성할 수는 없지만, 다른 클래스가 상속받아 
            // 구체적인 기능을 만들 수 있도록 설계되어 있는 클래스

            Terrain cave = new Cave(250,400);
            Terrain graveyard = new Graveyard(500,200);
            Terrain coast = new Coast(800,1000);

            cave.Description();
            graveyard.Description();
            coast.Description();

            Console.WriteLine($"Cave width : {cave.Width}, Cave height : {cave.Height}\n");
            Console.WriteLine($"Graveyard width : {graveyard.Width}, Graveyard height : {graveyard.Height}\n");
            Console.WriteLine($"Coast width : {coast.Width}, Coast height : {coast.Height}\n");

            Terrain[] terrains = { cave, graveyard, coast };

            List<ICoverable> coverables = new List<ICoverable>();

            foreach( var t in terrains )
            {
                if(t is ICoverable coverable)
                {
                    coverables.Add(coverable);
                }
            }

            foreach(var c in coverables)
            {
                c.TakeCover();
            }

            #endregion
        }
    }
}
