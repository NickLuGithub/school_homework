using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace b10702057_pc12
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        void random_array(int[] a, int n)
        {
            Random r = new Random();
            for (int i = 0; i < n; i++)
            {
                a[i] = r.Next(n) + 1;
                for (int j = 0; j < i; j++)
                    if (a[i] == a[j])
                    {
                        --i;
                        break;
                    }
            }
        }
        void even_random_array(int[] a, int n)
        {
            random_array(a, n);
            for (int i = 0; i < n; i++) a[i] *= 2;
        }
        void odd_random_array(int[] a, int n)
        {
            random_array(a, n);
            for (int i = 0; i < n; i++) a[i] = a[i] * 2 - 1;
        }
        void pair_random_array(int[] a, int n)
        {
            random_array(a, n);
            for (int i = 0; i < n; i++) a[i] = (a[i] + 1) / 2;
        }
        string to_2d_array_str(int[] a, bool[] b, int n)
        {
            string s = "";
            for (int i = 0, k = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++, k++) s += b[k] ? a[k] + " " : " * ";
                s += "</br>";
            }
            return s;
        }
        void setMask(bool[] b, bool flag, int n)
        {
            for ( int i= 0, k = 0; i < n; i++)
            {
                for (int l = 0; l < n; l++) b[k++] = flag;
            }
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int n = Convert.ToInt32(TextBox1.Text);
            int[] a = new int[n * n];
            bool[] b = new bool[n * n];
            setMask(b, true, n);
            string s = "";

            Random r = new Random();
            int i = r.Next(n * n), j = r.Next(n * n);
            b[i] = b[j] = true;
            random_array(a, n * n);
            s += to_2d_array_str(a, b, n) + "</p>";
            even_random_array(a, n * n);
            s += to_2d_array_str(a, b, n) + "</p>";
            odd_random_array(a, n * n);
            s += to_2d_array_str(a, b, n) + "</p>";
            pair_random_array(a, n * n);
            s += to_2d_array_str(a, b, n) + "</p>";

            Label1.Text = s;

        }
    }
}