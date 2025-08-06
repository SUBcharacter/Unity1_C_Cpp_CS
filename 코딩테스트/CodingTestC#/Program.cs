using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;

public class SoundOption
{
    float BGM;
    float SE;
    
    void init()

    void SetBGMVolume(float rate)
    {
        BGM = rate;
    }

    void SetSEVolume(float rate) 
    {
        SE = rate;
    }

}

public class Solution
{
    public int[] solution(string my_string)
    {
        List<int> list = new List<int>();

        for (int i = 0; i < my_string.Length; i++)
        {
            if (char.IsDigit(my_string[i]))
            {
                list.Add(my_string[i] - '0');
            } 
        }

        list.Sort();

        int[] result = new int[list.Count];

        for(int i = 0; i < list.Count;i++)
        {
            result[i] = list[i];
        }

        return result;
    }
}

public class Program
{
    public static void Main()
    {
        Dictionary<1>
    }
}
