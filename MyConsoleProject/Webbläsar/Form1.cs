using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Webbläsar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnGo_Click(object sender, EventArgs e)
        {
            browserWindow.Navigate(tbURL.Text);

        }

        private void aboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            AboutBox aboutBox = new AboutBox();
            aboutBox.ShowDialog();
        }

        private void navigateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Navigate myNavigateBox = new Navigate();
            if (myNavigateBox.ShowDialog() == DialogResult.OK)
                browserWindow.Navigate(myNavigateBox.txtURL.Text);

        }
    }
}
