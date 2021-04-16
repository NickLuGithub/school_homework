using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace b10702057_cp5
{
    class BMI
    {
        static void Main(string[] args)
        {
            Console.Write("Enter your height(cm) and weight(kg): ");
            string[] input = Console.ReadLine().Split(' ');
            double height = Convert.ToDouble(input[0]), weight = Convert.ToDouble(input[1]);
            double bmi = weight / (height / 100 * height / 100);
            Console.WriteLine("Your BMI is " + bmi);

            if (bmi < 18) Console.WriteLine("太瘦囉!");
            else if (bmi > 24) Console.WriteLine("太胖囉!");
            else Console.WriteLine("完美身材!");
        }
    }
}
