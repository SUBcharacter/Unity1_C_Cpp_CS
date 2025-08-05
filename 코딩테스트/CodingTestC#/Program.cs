using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public List<(int number, int count)> solution(int[] numbers)
    {
        Dictionary<int ,int> dict = new Dictionary<int, int> ();
        
        foreach(int i in numbers)
        {
            if(dict.ContainsKey(i))
            {
                dict[i]++;
            }
            else
            {
                dict[i] = 1;
            }
        }

        List<(int number, int count)> result = dict
            .OrderByDescending(pair => pair.Value)
            .Select(pair => (pair.Key, pair.Value))
            .ToList();

        return result;
    }
}

public class Program
{
    public static void Main()
    {
        var sol = new Solution();
        var counts = sol.solution([2, 1, 2, 1, 2, 3]);

        foreach(var i in counts)
        {
            Console.WriteLine($"number : {i.number} , count : {i.count}");
        }
        
    }
}
