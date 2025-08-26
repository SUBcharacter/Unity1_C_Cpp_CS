using System.Data.SqlTypes;
using System.Numerics;

namespace Program
{
    

    internal class Program
    {
        

        static void Main()
        {
            #region 컬렉션

            #region List

            //List<int> list = new List<int>();
            //
            //list.Add(10); // push_back(10);
            //list.Add(20); // push_back(20);
            //list.Add(30); // push_back(30);
            //list.Add(40); // push_back(40);
            //list.Add(50); // push_back(50);
            //
            //list.Remove(15);
            //
            //foreach(int i in list)
            //{
            //    Console.WriteLine(i);
            //}

            #endregion

            #region Dictionary

            Dictionary<string,int> dic = new Dictionary<string,int>();

            dic.Add("Blade", 50);
            dic.Add("Decade", 100);
            dic.Add("Faiz", 200);

            foreach(var item in dic)
            {
                Console.WriteLine($"KEY : {item.Key}");
                Console.WriteLine($"VALUE : {item.Value}");
            }

            

            #endregion

            #endregion
        }
    }
}
