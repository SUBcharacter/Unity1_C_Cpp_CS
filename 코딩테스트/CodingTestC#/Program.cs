using System;

public class Solution
{
    public string solution(string content, string bannedTags)
    {
        string[] words = content.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        string[] banned1 = bannedTags.Split(' ', StringSplitOptions.RemoveEmptyEntries);
        string[] banned2 = bannedTags.Split(',', StringSplitOptions.RemoveEmptyEntries);

        foreach(string word in words)
        {
            foreach(string bannedTag in banned1)
            {
                if(word == bannedTag)
                {
                    return "BLOCK";
                }
            }
        }

        foreach (string word in words)
        {
            foreach (string bannedTag in banned2)
            {
                if (word == bannedTag)
                {
                    return "BLOCK";
                }
            }
        }

        return "ALLOW";
    }
}

public class Program
{
    public static void Main()
    {
        var sol = new Solution();

        Console.WriteLine(sol.solution("I want a refund","refun"));
    }
}
