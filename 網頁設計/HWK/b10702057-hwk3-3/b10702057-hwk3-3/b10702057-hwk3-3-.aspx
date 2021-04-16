<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="b10702057-hwk3-3-.aspx.cs" Inherits="b10702057_hwk3_3.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:TextBox ID="number_1" runat="server" Width="100px"></asp:TextBox>
&nbsp;+
            <asp:TextBox ID="number_i1" runat="server" Width="100px"></asp:TextBox>
&nbsp;i
            <asp:DropDownList ID="DropDownList1" runat="server">
                <asp:ListItem>+</asp:ListItem>
                <asp:ListItem>-</asp:ListItem>
                <asp:ListItem>*</asp:ListItem>
                <asp:ListItem Value="/"></asp:ListItem>
            </asp:DropDownList>
            <asp:TextBox ID="number_2" runat="server" Width="100px"></asp:TextBox>
&nbsp;+
            <asp:TextBox ID="number_i2" runat="server" Width="100px"></asp:TextBox>
            &nbsp;i
            <asp:Button ID="Calculate1" runat="server" OnClick="Calculate1_Click" Text="Calculate" />
            <br />
            <asp:Label ID="Label1" runat="server"></asp:Label>
        </div>
    </form>
</body>
</html>
