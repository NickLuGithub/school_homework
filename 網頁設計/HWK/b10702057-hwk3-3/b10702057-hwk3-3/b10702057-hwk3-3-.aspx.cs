using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace b10702057_hwk3_3
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        protected void Calculate1_Click(object sender, EventArgs e)
        {
            double a, ai, b, bi, c, ci;
            a = Convert.ToDouble(number_1.Text);
            ai = Convert.ToDouble(number_i1.Text);
            b = Convert.ToDouble(number_2.Text);
            bi = Convert.ToDouble(number_i2.Text);

            Label1.Text = "(" + a + " + " + ai + "i)" + DropDownList1.SelectedValue + "(" + b + " + " + bi + "i) = ";

            switch (DropDownList1.SelectedValue)
            {
                case "+":
                    c = a + b;
                    ci = ai + bi;
                    Label1.Text += c + " + " + ci + "i";
                    break;
                case "-":
                    c = a - b;
                    ci = ai - bi;
                    Label1.Text += c + " + " + ci + "i";
                    break;
                case "*":
                    c = a * b - ai * bi;
                    ci = ai * b + a * bi;
                    Label1.Text += c + " + " + ci + "i";
                    break;
                case "/":
                    if(b * b + bi * bi == 0)
                    {
                        Label1.Text += "is undefined.";
                    }
                    else
                    {
                        c = (a * b + ai * bi) / (b * b + bi * bi);
                        ci = (ai * b - a * bi) / (b * b + bi * bi);
                        Label1.Text +=  c + " + " + ci + "i";
                    }
                    break;
            }
        }
    }
}