<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="b10702057.aspx.cs" Inherits="b10702057.b10702057" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <p style="language:zh-TW;margin-top:0pt;margin-bottom:0pt;margin-left:0in;
text-align:left;direction:ltr;unicode-bidi:embed;mso-line-break-override:none;
word-break:normal;punctuation-wrap:hanging">
            <span style="font-size: 10.0pt; font-family: &quot;Times New Roman&quot;; mso-ascii-font-family: &quot;Times New Roman&quot;; mso-fareast-font-family: 細明體; mso-bidi-font-family: &quot;Times New Roman&quot;; color: black; background: white; mso-highlight: white; mso-font-kerning: 12.0pt; language: en-US; mso-style-textfill-type: solid; mso-style-textfill-fill-color: black; mso-style-textfill-fill-alpha: 100.0%">Student No:</span><asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        </p>
        <p style="language:zh-TW;margin-top:0pt;margin-bottom:0pt;margin-left:0in;
text-align:left;direction:ltr;unicode-bidi:embed;mso-line-break-override:none;
word-break:normal;punctuation-wrap:hanging">
            <span style="font-size: 10.0pt; font-family: &quot;Times New Roman&quot;; mso-ascii-font-family: &quot;Times New Roman&quot;; mso-fareast-font-family: 細明體; mso-bidi-font-family: &quot;Times New Roman&quot;; color: black; background: white; mso-highlight: white; mso-font-kerning: 12.0pt; language: en-US; mso-style-textfill-type: solid; mso-style-textfill-fill-color: black; mso-style-textfill-fill-alpha: 100.0%">First Name:</span><asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        </p>
        <p style="language:zh-TW;margin-top:0pt;margin-bottom:0pt;margin-left:0in;
text-align:left;direction:ltr;unicode-bidi:embed;mso-line-break-override:none;
word-break:normal;punctuation-wrap:hanging">
            <span style="font-size: 10.0pt; font-family: &quot;Times New Roman&quot;; mso-ascii-font-family: &quot;Times New Roman&quot;; mso-fareast-font-family: 細明體; mso-bidi-font-family: &quot;Times New Roman&quot;; color: black; background: white; mso-highlight: white; mso-font-kerning: 12.0pt; language: en-US; mso-style-textfill-type: solid; mso-style-textfill-fill-color: black; mso-style-textfill-fill-alpha: 100.0%">Last Name:</span><asp:TextBox ID="TextBox3" runat="server" OnTextChanged="TextBox3_TextChanged"></asp:TextBox>
        </p>
        <p style="language:zh-TW;margin-top:0pt;margin-bottom:0pt;margin-left:0in;
text-align:left;direction:ltr;unicode-bidi:embed;mso-line-break-override:none;
word-break:normal;punctuation-wrap:hanging">
            <span style="font-size: 10.0pt; font-family: &quot;Times New Roman&quot;; mso-ascii-font-family: &quot;Times New Roman&quot;; mso-fareast-font-family: 細明體; mso-bidi-font-family: &quot;Times New Roman&quot;; color: black; background: white; mso-highlight: white; mso-font-kerning: 12.0pt; language: en-US; mso-style-textfill-type: solid; mso-style-textfill-fill-color: black; mso-style-textfill-fill-alpha: 100.0%">Major:</span><asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
        </p>
        <span style="font-size: 10.0pt; font-family: &quot;Times New Roman&quot;; mso-ascii-font-family: &quot;Times New Roman&quot;; mso-fareast-font-family: 細明體; mso-bidi-font-family: &quot;Times New Roman&quot;; color: black; background: white; mso-highlight: white; mso-font-kerning: 12.0pt; language: en-US; mso-style-textfill-type: solid; mso-style-textfill-fill-color: black; mso-style-textfill-fill-alpha: 100.0%">Birthdate:<asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
        </span>
        <br />
        <asp:Button ID="Button1" runat="server" OnClick="Button1_Click" Text="Insert" />
        <asp:Button ID="Button2" runat="server" OnClick="Button2_Click" Text="Update" />
        <asp:Button ID="Button3" runat="server" OnClick="Button3_Click" Text="Delete" />
        <asp:Button ID="Button4" runat="server" OnClick="Button4_Click" Text="List" />
        <asp:Button ID="Button5" runat="server" OnClick="Button5_Click" Text="Query" />
        <br />
        <asp:Label ID="Label1" runat="server"></asp:Label>
    
    </div>
    </form>
</body>
</html>
