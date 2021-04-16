using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace GuessNumber
{
    public partial class GuessNumber : System.Web.UI.Page
    {
        int number;

        private void RandNumber()
        {
            Random r = new Random();
            number = r.Next(10) + 1;
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            RandNumber();
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            int guess = Convert.ToInt32(TextBox1.Text);
            if (guess > number) Label1.Text = "Too large! Try again!";
            else if (guess < number) Label1.Text = "Too small! Try again!";
            else Label1.Text = "Correct! Smart guy!";
            Label.Text += number;
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            RandNumber();
        }
    }
}
