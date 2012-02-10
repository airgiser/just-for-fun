using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace WebBrowser
{
    public partial class WebBrowser : Form
    {
        public WebBrowser()
        {
            InitializeComponent();
        }

        private void goButton_Click(object sender, EventArgs e)
        {
            webBrowserForm.Navigate(new Uri(address.SelectedItem.ToString()));
        }

        private void homeToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webBrowserForm.GoHome();
        }

        private void backToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webBrowserForm.GoBack();
        }

        private void forwardToolStripMenuItem_Click(object sender, EventArgs e)
        {
            webBrowserForm.GoForward();
        }

        private void WebBrowser_Load(object sender, EventArgs e)
        {
            address.SelectedIndex = 0;
            webBrowserForm.GoHome();
        }
    }
}