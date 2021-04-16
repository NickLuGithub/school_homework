<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="mian.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<style>
body {
  background-color: red;
  background-repeat: no-repeat;
  background-attachment: fixed;
  background-size: 100% 100%;
}
</style>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>醫療系統</h1>
        </div>
        <h2 style="width: 775px">
        請輸入病患資料<asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="輸入" />
        <asp:Button ID="Button2" runat="server" Text="更新" OnClick="Button2_Click" />
        <asp:Button ID="Button3" runat="server" Text="刪除" OnClick="Button3_Click" />
        <asp:Button ID="Button4" runat="server" Text="列表" OnClick="Button4_Click" />
        <asp:Button ID="Button5" runat="server" Text="查詢" OnClick="Button5_Click" />
            <br />
        身分證 <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <br />
        姓名 <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        <br />
        地址 <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
        <br />
        生日 <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
        <br />
        血型<asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
        <br />
        過敏史<asp:TextBox ID="TextBox6" runat="server"></asp:TextBox>
        <br />
        電話<asp:TextBox ID="TextBox7" runat="server"></asp:TextBox>
        </h2>
        <h2 style="width: 683px">
            查詢X光照片ID&nbsp; <asp:Button ID="Button6" runat="server" Text="查詢" OnClick="Button6_Click" />
        </h2>
        <h2 style="width: 456px">
            查詢同血型人&nbsp;&nbsp;&nbsp; <asp:Button ID="Button7" runat="server" OnClick="Button7_Click" Text="查詢" />
        <br/>
        </h2>
        <asp:Label ID="Label1" runat="server" Text=""></asp:Label>
        <br />
        <br />
    </form>
</body>
</html>
