using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Numerics;

public class SoundOption
{
    float BGM = 100.0f;
    float SE = 100.0f;

    public void LoadSetting(Dictionary<string,float> dict)
    {
        int index = 0;
        float[] values = new float[2];

        foreach(var key in dict.Keys)
        {
            values[index++] = dict[key];
        }

        BGM = values[0];
        SE = values[1];
    }

    public Dictionary<string,float> SaveOption()
    {
        var saveOption = new Dictionary<string,float>();

        saveOption["BGM"] = BGM;
        saveOption["SE"] = SE;

        return saveOption;
    }

    public void SetBGMVolume(float rate)
    {
        BGM = rate;
    }

    public void SetSEVolume(float rate)
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
        Dictionary<string, float> dict = new Dictionary<string, float>
        {
            { "BGM" , 30.0f},
            {"SE" , 50.0f}
        };

        var soundManager = new SoundOption();

        soundManager.LoadSetting(dict);

        Console.WriteLine(soundManager.BGM);
        Console.WriteLine(soundManager.SE);

        soundManager.SetBGMVolume(60.0f);
        soundManager.SetSEVolume(20.0f);

        Console.WriteLine(soundManager.BGM);
        Console.WriteLine(soundManager.SE);

        dict = soundManager.SaveOption();

        Console.WriteLine(dict["BGM"]);
        Console.WriteLine(dict["SE"]);

    }
}
