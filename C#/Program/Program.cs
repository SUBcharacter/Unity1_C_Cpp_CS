using System.Numerics;

namespace Program
{
    internal class Program
    {
        static void Main()
        {
            #region 박싱

            // 값 형식의 데이터를 참조 형식으로 변환하는 과정

            //int value = 100;
            //
            //object generic = value;
            //
            //Console.WriteLine(value);
            //Console.WriteLine(generic);

            #endregion

            #region 언박싱

            // 참조 형식의 데이터를 값 형식으로 변환하는 과정

            //int box = (int)generic;
            //
            //Console.WriteLine(box);

            #endregion

            Utility util = new Utility();

            util.Pause();

            int x = 10;
            int y = 20;

            Console.WriteLine($"{x} {y}");

            util.Swap(ref x, ref y);

            Console.WriteLine($"{x} {y}");

            int abs = 10;

            util.Absolute(in abs);
        }
    }
}
