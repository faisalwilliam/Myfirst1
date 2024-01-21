namespace PasswdTextBox
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tbPasswd = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lblShowPasswd = new System.Windows.Forms.Label();
            this.btnShowMe = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // tbPasswd
            // 
            this.tbPasswd.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(192)))), ((int)(((byte)(128)))));
            this.tbPasswd.Location = new System.Drawing.Point(26, 25);
            this.tbPasswd.Name = "tbPasswd";
            this.tbPasswd.PasswordChar = '*';
            this.tbPasswd.Size = new System.Drawing.Size(245, 20);
            this.tbPasswd.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(20, 25);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 13);
            this.label1.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(121, 99);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(0, 13);
            this.label2.TabIndex = 2;
            // 
            // lblShowPasswd
            // 
            this.lblShowPasswd.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(128)))));
            this.lblShowPasswd.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.lblShowPasswd.Location = new System.Drawing.Point(26, 79);
            this.lblShowPasswd.Name = "lblShowPasswd";
            this.lblShowPasswd.Size = new System.Drawing.Size(245, 20);
            this.lblShowPasswd.TabIndex = 3;
            // 
            // btnShowMe
            // 
            this.btnShowMe.BackColor = System.Drawing.Color.Red;
            this.btnShowMe.Location = new System.Drawing.Point(90, 150);
            this.btnShowMe.Name = "btnShowMe";
            this.btnShowMe.Size = new System.Drawing.Size(100, 40);
            this.btnShowMe.TabIndex = 4;
            this.btnShowMe.Text = "Show Me";
            this.btnShowMe.UseVisualStyleBackColor = false;
            this.btnShowMe.Click += new System.EventHandler(this.btnShowMe_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Blue;
            this.ClientSize = new System.Drawing.Size(463, 381);
            this.Controls.Add(this.btnShowMe);
            this.Controls.Add(this.lblShowPasswd);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbPasswd);
            this.Name = "Form1";
            this.Text = "PasswdTextBox";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox tbPasswd;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lblShowPasswd;
        private System.Windows.Forms.Button btnShowMe;
    }
}

