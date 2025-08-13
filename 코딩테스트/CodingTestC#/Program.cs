using System;

using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel.DataAnnotations;
using System.Text;

public class PacketManager
{
    public Queue<string> packetQueue;

    public PacketManager()
    {
        packetQueue = new Queue<string>();
    }

    public void EnqueuePacket(string packet)
    {
        if(packetQueue.Count > 10)
        {
            packetQueue.Dequeue();
            packetQueue.Enqueue(packet);
        }
        else
        {
            packetQueue.Enqueue(packet);
        }
    }

    public void ProcessPacket()
    {
        if(packetQueue.Count == 0)
            return;

        Console.WriteLine("[처리됨]" + packetQueue.Dequeue());
    }
}

public class Program
{
    public static void Main()
    {
        var packetManager = new PacketManager();

        packetManager.EnqueuePacket("채팅 1");
        packetManager.EnqueuePacket("채팅 2");
        packetManager.EnqueuePacket("채팅 3");
        packetManager.EnqueuePacket("채팅 4");
        packetManager.EnqueuePacket("채팅 5");
        packetManager.EnqueuePacket("채팅 6");
        packetManager.EnqueuePacket("채팅 7");
        packetManager.EnqueuePacket("채팅 8");
        packetManager.EnqueuePacket("채팅 9");
        packetManager.EnqueuePacket("채팅 10");
        packetManager.EnqueuePacket("채팅 11");

        for(int i = 0; i < 10; i++)
        {
            packetManager.ProcessPacket();
        }
    }
}
