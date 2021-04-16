<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="RadomNumber.aspx.cs" Inherits="PC.RadomNumber" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body style="width: 664px">
    <form id="form1" runat="server">
        <div>
            Guest a number ( 1 ~ 10 ) :
            <asp:TextBox ID="TextBox1" runat="server" Width="85px"></asp:TextBox>
            <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Enter" />
            <asp:Button ID="Button2" runat="server" Text="Rest" />
            <br />
            <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label>
        </div>
    </form>
</body>
</html>
