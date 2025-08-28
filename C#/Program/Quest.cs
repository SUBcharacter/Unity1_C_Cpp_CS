using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Program
{
    internal class Quest
    {
        private string title;
        private string description;
        private Reward reward;
        public bool completed = false;

        public Quest(string questTitle, string questDescription, Reward reward)
        {
            this.title = questTitle;
            this.description = questDescription;
            this.reward = reward;
        }

        public void Describe()
        {
            Console.WriteLine(title);
            Console.WriteLine(description +"\n");
            reward.Describe();
        }
    }
}
