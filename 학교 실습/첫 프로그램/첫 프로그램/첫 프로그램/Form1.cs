using System;
using System.Windows.Forms;
using System.Diagnostics;
using System.Drawing;

namespace 첫_프로그램
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            KeyDown += new KeyEventHandler(Form_InputEscDown);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 50;
        }

        private void Form_InputEscDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.F10) Application.Exit();
            if (e.KeyData == (Keys.Alt | Keys.F4)) e.Handled = true;
        }

        protected override CreateParams CreateParams
        {
            get
            {
                // Turn on WS_EX_TOOLWINDOW style bit
                CreateParams cp = base.CreateParams;
                cp.ExStyle |= 0x80;
                return cp;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // 지정된 주기마다 프로세스 목록 중 notepad라는 이름을 가진 프로세스의 핸들을 얻어옴

            Process[] mProcess = Process.GetProcessesByName("Taskmgr");
            if (mProcess.Length > 0) // 뭔가가 발견되면...
            {
                foreach (var item in mProcess)
                {
                    //item.Kill();
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ShowBox();
        }

        private void ShowBox()
        {
            MessageBox.Show("프로그램을 종료합니다.");
            ShowBox();
        }
    }
}
