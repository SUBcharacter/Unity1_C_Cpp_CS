namespace Collection
{
    internal class Program
    {
        static void Main(string[] args)
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

            //Dictionary<string,int> dic = new Dictionary<string,int>();
            //
            //dic.Add("Blade", 50);
            //dic.Add("Decade", 100);
            //dic.Add("Faiz", 200);
            //
            //foreach(var item in dic)
            //{
            //    Console.WriteLine($"KEY : {item.Key}");
            //    Console.WriteLine($"VALUE : {item.Value}");
            //}



            #endregion

            #region Stack

            //Stack<int> stack = new Stack<int>();
            //
            //stack.Push(10);
            //stack.Push(20);
            //stack.Push(30);
            //stack.Push(40);
            //stack.Push(50);
            //
            //while(stack.Count > 0)
            //{
            //    Console.WriteLine(stack.Pop());
            //}

            #endregion

            #region Queue

            //Queue<int> queue = new Queue<int>();
            //
            //queue.Enqueue(10);
            //queue.Enqueue(20);
            //queue.Enqueue(30);
            //queue.Enqueue(40);
            //queue.Enqueue(50);
            //
            //while(queue.Count > 0)
            //{
            //    Console.WriteLine(queue.Dequeue());
            //}

            #endregion

            #region Linked List

            LinkedList<int> list = new LinkedList<int>();

            list.AddFirst(10);
            list.AddFirst(5);
            list.AddFirst(1);
            list.AddLast(20);

            foreach (int i in list)
            {
                Console.WriteLine(i);
            }

            #endregion

            #endregion
        }
    }
}
