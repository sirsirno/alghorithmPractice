using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static System.Console;
namespace algorithm_summer_03
{
    class Program
    {
        static string HidePhoneNum(string phoneNum)
        {
            return $"***-****-{phoneNum[9]}{phoneNum[10]}{phoneNum[11]}{phoneNum[12]}";
        }
        static void Main(string[] args)
        {
            string phoneNumber = ReadLine();
            if(phoneNumber.Length>20 | phoneNumber.Length <4)
            {
                WriteLine(" 문자열은 길이가 4 이상, 20 이하인 문자열이어야 합니다.");
                return;
            }
            string modifiedNum = phoneNumber.Insert(3, "-");
            string modifiedNum2 = modifiedNum.Insert(8, "-");

           WriteLine(HidePhoneNum(modifiedNum2));
        }

      

    }
}
