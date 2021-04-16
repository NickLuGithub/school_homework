using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;

namespace b10702057
{
    public partial class b10702057 : System.Web.UI.Page
    {
        string connetionString = "";
        SqlConnection connection = null;
        protected void Page_Load(object sender, EventArgs e)
        {
            connetionString = "Data Source=localhost\\SQLEXPRESS;Initial Catalog=University;User ID=nick;Password=123456";
            // 資料庫連接字串
            connection = new SqlConnection(connetionString);
        }

        protected void TextBox3_TextChanged(object sender, EventArgs e)
        {

        }

        protected void Button1_Click(object sender, EventArgs e)
        {
            string studentid = TextBox1.Text, lastname = TextBox2.Text,     // 取得欄位輸入值
                firstname = TextBox3.Text, major = TextBox4.Text, birthdate = TextBox5.Text;
            string sql = "insert into student values ('" + studentid + "', '" + lastname + "', '" +    // SQL字串
                         firstname + "', '" + major + "', '" + birthdate + "')";
            Label1.Text = "";                                                                                       // 結果標籤設為""
            try
            {
                connection.Open();                                                                                // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);          // 建立SQL命令
                command.ExecuteNonQuery();                                                            // 執行非查詢命令
                command.Dispose();                                                                             // 拋掉指令
                connection.Close();                                                                               // 關閉資料庫連接
                Label1.Text = "Insert data successfully!";                                            // 顯示成功地加入資料
            }
            catch (Exception ex)
            {
                Label1.Text = ex.ToString();
            }
        }

        protected void Button2_Click(object sender, EventArgs e)
        {
            string studentid = TextBox1.Text, major = TextBox4.Text;                  // 取得欄位輸入值
            string sql = "update student set major = '" + major +
                            "' where studentid = '" + studentid + "'";                               // SQL字串：修改學生主修
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
            string studentid = TextBox1.Text;                                   // 取得學生ID欄位輸入值
            string sql = "delete from student where studentid = '" + studentid + "'";  // SQL字串：刪除學生資料
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
            string sql = "select studentid, lastname, firstname, major, " +       // SQL字串：選取所有的學生
                     "format(birthdate, 'yyyy-MM-dd') from student";
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
                        + dataReader.GetValue(3) + " " + dataReader.GetValue(4) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                  // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }
        }

        protected void Button5_Click(object sender, EventArgs e)
        {
            string major = TextBox4.Text;                                                            // 取得主修欄位輸入值
            string sql = "select studentid, lastname, firstname, major, " +           // SQL字串：選取主修為major的學生
                         "format(birthdate, 'yyyy-MM-dd') from student where " +
                         " major = '" + major + "'";
            Label1.Text = "";
            try
            {
                connection.Open();                                                                        // 開啟連接
                SqlCommand command = new SqlCommand(sql, connection);  // 建立SQL命令
                SqlDataReader dataReader = command.ExecuteReader();          // 執行讀取命令返回資料讀取器
                while (dataReader.Read())
                {                                                        // 當還有資料，顯示查詢結果
                    Label1.Text += dataReader.GetValue(0) + " "
                        + dataReader.GetValue(1) + " " + dataReader.GetValue(2) + " "
                        + dataReader.GetValue(3) + " " + dataReader.GetValue(4) + "<br/>";
                }
                dataReader.Close();                                                    // 關閉資料讀取器
                command.Dispose();                                                    // 拋掉指令
                connection.Close();                                                    // 關閉資料庫連接
            }
            catch (Exception ex) { Label1.Text = ex.ToString(); }
        }
    }
}