<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="b10702057-hwk3-2.aspx.cs" Inherits="T1.b10702057_hwk3_2" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        遊戲狀態：<asp:Label ID="Label1" runat="server"></asp:Label>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="開始" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="結束" />
        <br />
        ==========================<br />
        1: NT $300<br />
        2: Play again!<br />
        3: Thanks for your play!<br />
        4: NT $100<br />
        5: Thanks for your play!<br />
        6: Thanks for your play!<br />
        7: Play again!<br />
        8: Thanks for your play!<br />
        9: Thanks for your play!<br />
        10: NT $200<br />
        11: Thanks for your play!<br /> 
        12: NT $500
        <br />
        ==========================<br />
        加值（以百為單位）：<asp:Label ID="YNpoint" runat="server"></asp:Label>
        <br />
        <asp:TextBox ID="TextBox1" runat="server" Width="127px"></asp:TextBox>
        <asp:Button ID="inpoint" runat="server" Text="加值" OnClick="Button3_Click" />
        <br />
        ==========================<br />
        目前所剩金錢：<asp:Label ID="PointTotal" runat="server"></asp:Label>
        <br />
        --------------------------------------------<br />
        遊戲遊玩狀態：<asp:Button ID="Button3" runat="server" Height="26px" OnClick="Button3_Click1" Text="玩一次" Width="107px" />
        <br />
        <asp:Label ID="Label2" runat="server"></asp:Label>
    </form>
</body>
</html>
