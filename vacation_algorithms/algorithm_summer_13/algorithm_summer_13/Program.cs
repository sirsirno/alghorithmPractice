using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace algorithm_summer_13
{
    class Program
    {
        static char[] syzerPassword(char[] str, int count)
        {

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == ' ')
                continue;

                if (str[i] == 'z' || str[i] == 'Z')
                    str[i] = str[i] == 'z'
                        ? str[i] = Convert.ToChar('a' - 1 )
                        : str[i] = Convert.ToChar('A' - 1 );

                str[i] = Convert.ToChar(str[i] + count); 
            }

            return str;
        }

        static void Main(string[] args)
        {
            int distance = int.Parse(ReadLine());
            char[] syzerString = ReadLine().ToCharArray();

            if(distance <1 || distance > 25 || syzerString.Length > 8000 || syzerString.GetType() == null)
            {
                WriteLine(" 알파벳 소문자, 대문자 , 공백으로 문자열을 구성해야 합니다. 정수의 길이는 1이상 25이하여야 합니다.");

                return;
            }

            foreach (var item in syzerPassword(syzerString, distance))
            {
                WriteLine(item);
            }
           


        }
    }
}
