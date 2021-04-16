using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace T1
{
    public partial class b10702057_hwk3_2 : System.Web.UI.Page
    {
        static int op = -1;
        static int point = 0;
        protected void Page_Load(object sender, EventArgs e)
        {
            Label1.Text = ("請問是否遊玩");
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            if(op != 0)
            {
                op = 1;
                Label1.Text = ("遊玩遊戲中");
                string k;
                k = "" + point;
                PointTotal.Text = k;
            }
            else
            {
                Label1.Text = ("謝謝遊玩");
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            op = 0;
            Label1.Text = ("謝謝遊玩");
        }

        protected void Button3_Click(object sender, EventArgs e)
        {
            if(op == 1)
            {
                int a = Convert.ToInt16(TextBox1.Text);
                if(a % 100 == 0)
                {
                    point += a;
                    YNpoint.Text = "加值成功";
                    string k;
                    k = "" + point;
                    PointTotal.Text = k;
                }
                else
                {
                    YNpoint.Text = "加值失敗";
                }
            }
            else
            {
                Label1.Text = "謝謝遊玩";
            }
        }

        protected void Button3_Click1(object sender, EventArgs e)
        {
            if (op == 1)
            {
                if (point >= 50)
                {
                    point -= 50;
                    string k;
                    k = "" + point;
                    PointTotal.Text = k;

                    Random ran = new Random();
                    int n = ran.Next(1, 12);
                    switch (n)
                    {
                        case 1:
                            Label2.Text = "Your roll is 1.\nYou won NT $300.";
                            point += 300;
                            string t1;
                            t1 = "" + point;
                            PointTotal.Text = t1;
                            break;
                        case 2:
                            Label2.Text = "Your roll is 2.\nPlay again!";
                            break;
                        case 3:
                            Label2.Text = "Your roll is 3.\nThanks for your play!";
                            break;
                        case 4:
                            Label2.Text = "Your roll is 4.\nYou won NT $100.";
                            point += 100;
                            string t2;
                            t2 = "" + point;
                            PointTotal.Text = t2;
                            break;
                        case 5:
                            Label2.Text = "Your roll is 5.\nThanks for your play!";
                            break;
                        case 6:
                            Label2.Text = "Your roll is 6.\nThanks for your play!";
                            break;
                        case 7:
                            Label2.Text = "Your roll is 7.\nPlay again!";
                            break;
                        case 8:
                            Label2.Text = "Your roll is 8.\nThanks for your play!";
                            break;
                        case 9:
                            Label2.Text = "Your roll is 9.\nThanks for your play!";
                            break;
                        case 10:
                            Label2.Text = "Your roll is 10.\nYou won NT $200.";
                            point += 200;
                            string t3;
                            t3 = "" + point;
                            PointTotal.Text = t3;
                            break;
                        case 11:
                            Label2.Text = "Your roll is 11.\nThanks for your play!";
                            break;
                        case 12:
                            Label2.Text = "Your roll is 12.\nYou won NT $500.";
                            point += 500;
                            string t4;
                            t4 = "" + point;
                            PointTotal.Text = t4;
                            break;
                    }
                }
                else
                {
                    Label2.Text = "餘額不足，請加值或點選最上方結束開遊戲";
                }
            }
            else
            {
                Label1.Text = "謝謝遊玩";
            }
        }
    }
}