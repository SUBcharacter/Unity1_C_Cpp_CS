using System;

using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel.DataAnnotations;
using System.Text;

public class SyncManager
{
    public Dictionary<string, int> clientData;
    public Dictionary<string, int> serverData;

    public SyncManager()
    {
        clientData = new Dictionary<string, int>();
        serverData = new Dictionary<string, int>();

        clientData["AP"] = 50;
        clientData["Level"] = 89;
        clientData["Gold"] = 150000;
    }

    public void Sync(Dictionary<string, int> dict)
    {
        UpdateData(dict);
        clientData = serverData;
        Console.WriteLine("서버 동기화 완료");
    }

    public void UpdateData(Dictionary<string, int> dict)
    {
        serverData = dict;
        Console.WriteLine("서버로 부터 데이터 받아오는 중...");
    }
}

public class Solution
{
    
}

public class Program
{
    public static void Main()
    {
        Dictionary<string, int> data = new Dictionary<string, int>();
        data["AP"] = 100;
        data["Level"] = 90;
        data["Gold"] = 200000;

        SyncManager syncManager = new SyncManager();

        Console.WriteLine(syncManager.clientData["AP"]);
        Console.WriteLine(syncManager.clientData["Level"]);
        Console.WriteLine(syncManager.clientData["Gold"]);

        syncManager.Sync(data);

        Console.WriteLine(syncManager.clientData["AP"]);
        Console.WriteLine(syncManager.clientData["Level"]);
        Console.WriteLine(syncManager.clientData["Gold"]);
    }
}
