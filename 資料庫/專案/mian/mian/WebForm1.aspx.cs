using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace mian
{
    public partial class WebForm1 : System.Web.UI.Page
    {
        string connetionString = "";
        SqlConnection connection = null;

        protected void Page_Load(object sender, EventArgs e)
        {
            connetionString =
          "Data Source=localhost\\SQLEXPRESS;Initial Catalog=hospital;User ID=nick;Password=123456";
            // 資料庫連接字串
            connection = new SqlConnection(connetionString);
        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string  Idcard = TextBox1.Text,
                    Name = TextBox2.Text,
                    Address = TextBox3.Text,
                    Birthday = TextBox4.Text,
                    Blood = TextBox5.Text,
                    Allergy = TextBox6.Text,
                    Phone = TextBox7.Text;
            string sql = "insert into Patient values ('" + Idcard + "', '" + Name +
                         "', '" + Address + "', '" + Birthday + "', '" + Blood + 
                         "', '" + Allergy + "', '" + Phone + "')";
            Label1.Text = "";                                                                                      
            try
            {
                connection.Open();                                                                               
                SqlCommand command = new SqlCommand(sql, connection);          
                command.ExecuteNonQuery();                                                           
                command.Dispose();                                                                             
                connection.Close();                                                                              
                Label1.Text = "Insert data successfully!";          
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            string Idcard = TextBox1.Text,
                   Address = TextBox3.Text,
                   Phone = TextBox7.Text;
            string sql = "update Patient set Phone = '" + Phone + "', Address '" + Address +
                         "' where Idcard = '" + Idcard + "'";
            Label1.Text = "";                                                                                // 結果標籤設為""
            try
            {
                connection.Open();                                                                         // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);   // 建立SQL命令
                command.ExecuteNonQuery();                                                     // 執行非查詢命令
                command.Dispose();                                                                      // 拋掉指令
                connection.Close();                                                                        // 關閉資料庫連接
                Label1.Text = "Update data successfully!";                                  // 顯示成功地更新資料                             
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }

        }

        protected void Button3_Click(object sender, EventArgs e)
        {
            string Idcard = TextBox1.Text;
            string sql = "delete from Patient where Idcard = '" + Idcard + "'";  // SQL字串：刪除學生資料
            Label1.Text = "";
            try
            {
                connection.Open();                                                                         // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);    // 建立SQL命令
                command.ExecuteNonQuery();                                                      // 執行非查詢命令
                command.Dispose();                                                                       // 拋掉指令
                connection.Close();                                                                         // 關閉資料庫連接
                Label1.Text = "Delete data successfully!";                                     // 顯示成功地刪除資料    
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }

        }

        protected void Button4_Click(object sender, EventArgs e)
        {
            string sql = "select Idcard,Name,Address,Birthday, " +       // SQL字串：選取所有的學生
                     "Blood,Allergy,Phone from Patient";
            Label1.Text = "";
            try
            {
                connection.Open();                                                                       // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);  // 建立SQL命令
                SqlDataReader dataReader = command.ExecuteReader();   // 執行讀取命令返回資料讀取器
                while (dataReader.Read())
                {                                                 // 當還有資料，顯示查詢結果
                    Label1.Text += dataReader.GetValue(0) + " "
                        + dataReader.GetValue(1) + " " + dataReader.GetValue(2) + " "
                        + dataReader.GetValue(3) + " " + dataReader.GetValue(4) + " " + dataReader.GetValue(5) + " " + dataReader.GetValue(6) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                  // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }

        }

        protected void Button5_Click(object sender, EventArgs e)
        {
            string Idcard = TextBox1.Text;
            string sql = "select Idcard,Name,Address,Birthday, " +       // SQL字串：選取所有的學生
                     "Blood,Allergy,Phone from Patient where Idcard='"+Idcard+"'";
            Label1.Text = "";
            try
            {
                connection.Open();                                                                        // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);  // 建立SQL命令
                SqlDataReader dataReader = command.ExecuteReader();          // 執行讀取命令返回資料讀取器
                while (dataReader.Read())
                {                                                        // 當還有資料，顯示查詢結果
                    Label1.Text +=  "身分證: " + dataReader.GetValue(0) + "<br/>"
                                +   "姓名: "   + dataReader.GetValue(1) + "<br/>"
                                +   "地址: "   + dataReader.GetValue(2) + "<br/>"
                                +   "生日: "   + dataReader.GetValue(3) + "<br/>"
                                +   "血型: "   + dataReader.GetValue(4) + "<br/>" 
                                +   "過敏史: " + dataReader.GetValue(5) + "<br/>"
                                +   "電話: "   + dataReader.GetValue(6) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                    // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }

        }

        protected void Button6_Click(object sender, EventArgs e)
        {
            string Idcard = TextBox1.Text;
            string sql = "select p.Idcard, p.Name, i.Imageid " +
                         "from Image as i, Patient as p where i.Idcard = '" + Idcard + "' and p.Idcard = '" + Idcard + "'";
            Label1.Text = "";
            try
            {
                connection.Open();                                                                        // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);  // 建立SQL命令
                SqlDataReader dataReader = command.ExecuteReader();          // 執行讀取命令返回資料讀取器
                while (dataReader.Read())
                {                                                        // 當還有資料，顯示查詢結果
                    Label1.Text += "身分證: " + dataReader.GetValue(0) + "<br/>"
                                + "姓名: " + dataReader.GetValue(1) + "<br/>"
                                + "X光片ID: " + dataReader.GetValue(2) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                    // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }
        }

        protected void Button7_Click(object sender, EventArgs e)
        {
            string Blood = TextBox5.Text;
            string sql = "select Idcard, Name " +       // SQL字串：選取所有的學生
                         "from Patient where Blood = '" + Blood + "'";
            Label1.Text = "";
            try
            {
                connection.Open();                                                                        // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);  // 建立SQL命令
                SqlDataReader dataReader = command.ExecuteReader();          // 執行讀取命令返回資料讀取器
                while (dataReader.Read())
                {                                                        // 當還有資料，顯示查詢結果
                    Label1.Text += "身分證: " + dataReader.GetValue(0) + "  "
                                +  "姓名: " + dataReader.GetValue(1) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                    // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }
        }
    }
}
