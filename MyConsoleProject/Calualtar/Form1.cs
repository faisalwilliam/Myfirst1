using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calualtar
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double no1 = Convert.ToDouble(textBox1.Text);
            double no2 = Convert.ToDouble(textBox2.Text);
            textBox3.Text = (no1 + no2).ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double no1 = Convert.ToDouble(textBox1.Text);
            double no2 = Convert.ToDouble(textBox2.Text);
            textBox3.Text = (no1 - no2).ToString();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double no1 = Convert.ToDouble(textBox1. Text);
            double no2 = Convert.ToDouble(textBox2.Text);
            textBox3.Text = (no1 * no2).ToString();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double no1 = Convert.ToDouble(textBox1.Text);
            double no2 = Convert.ToDouble(textBox2.Text);
            textBox3.Text = (no1 /no2).ToString();
        }
    }
}
