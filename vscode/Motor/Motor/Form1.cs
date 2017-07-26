using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Motor
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            control_array_init();
            UartInit();
        }

        public SerialPort _MyPort;
        private delegate void DelegateSetCmdText(string text);
        public const int MOTOR_NUMBER = 12;
        public const int RELAY_NUMBER = 8;
        MotorControl[] motorlist = new MotorControl[MOTOR_NUMBER];

        private void textBox_KeyPress_check(object sender, KeyPressEventArgs e)
        {
            /* Is Number*/
            if (!Char.IsNumber(e.KeyChar) && e.KeyChar != (char)8)
            {
                e.Handled = true;
            }
        }

        private void control_array_init()
        {
            /*motor 1 control list*/
            //base
            motorlist[0].baseCB_ID = checkBox_m1;
            motorlist[0].baseTB_destination = textBox_m1_destination;
            motorlist[0].baseTB_initSpeed = textBox_m1_initspeed;
            motorlist[0].baseTB_speed = textBox_m1_speed;
            motorlist[0].baseTB_speedUp = textBox_m1_speedup;
            //para
            motorlist[0].paraCB_pulse = comboBox_m1_pulse;
            motorlist[0].paraCB_pulse.SelectedIndex = 1;
            motorlist[0].paraCB_positiveBit = comboBox_m1_positivebit;
            motorlist[0].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[0].paraCB_nagativeBit = comboBox_m1_nagativebit;
            motorlist[0].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[0].paraCB_stop0 = comboBox_m1_stop0;
            motorlist[0].paraCB_stop0.SelectedIndex = 1;
            motorlist[0].paraCB_stop1 = comboBox_m1_stop1;
            motorlist[0].paraCB_stop1.SelectedIndex = 0;
            motorlist[0].paraCB_level = comboBox_m1_level;
            motorlist[0].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[0].ioCB_positiveBit = checkBox_m1_IOIn_positivebit;
            motorlist[0].ioCB_nagativeBit = checkBox_m1_IOIn_nagativebit;
            motorlist[0].ioCB_stop0 = checkBox_m1_IOIn_STOP0;
            motorlist[0].ioCB_stop1 = checkBox_m1_IOIn_STOP1;

            /*motor 2 control list*/
            //base
            motorlist[1].baseCB_ID = checkBox_m2;
            motorlist[1].baseTB_destination = textBox_m2_destination;
            motorlist[1].baseTB_initSpeed = textBox_m2_initspeed;
            motorlist[1].baseTB_speed = textBox_m2_speed;
            motorlist[1].baseTB_speedUp = textBox_m2_speedup;
            //para
            motorlist[1].paraCB_pulse = comboBox_m2_pulse;
            motorlist[1].paraCB_pulse.SelectedIndex = 1;
            motorlist[1].paraCB_positiveBit = comboBox_m2_positivebit;
            motorlist[1].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[1].paraCB_nagativeBit = comboBox_m2_nagativebit;
            motorlist[1].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[1].paraCB_stop0 = comboBox_m2_stop0;
            motorlist[1].paraCB_stop0.SelectedIndex = 1;
            motorlist[1].paraCB_stop1 = comboBox_m2_stop1;
            motorlist[1].paraCB_stop1.SelectedIndex = 0;
            motorlist[1].paraCB_level = comboBox_m2_level;
            motorlist[1].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[1].ioCB_positiveBit = checkBox_m2_IOIn_positivebit;
            motorlist[1].ioCB_nagativeBit = checkBox_m2_IOIn_nagativebit;
            motorlist[1].ioCB_stop0 = checkBox_m2_IOIn_STOP0;
            motorlist[1].ioCB_stop1 = checkBox_m2_IOIn_STOP1;

            /*motor 3 control list*/
            //base
            motorlist[2].baseCB_ID = checkBox_m3;
            motorlist[2].baseTB_destination = textBox_m3_destination;
            motorlist[2].baseTB_initSpeed = textBox_m3_initspeed;
            motorlist[2].baseTB_speed = textBox_m3_speed;
            motorlist[2].baseTB_speedUp = textBox_m3_speedup;
            //para
            motorlist[2].paraCB_pulse = comboBox_m3_pulse;
            motorlist[2].paraCB_pulse.SelectedIndex = 1;
            motorlist[2].paraCB_positiveBit = comboBox_m3_positivebit;
            motorlist[2].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[2].paraCB_nagativeBit = comboBox_m3_nagativebit;
            motorlist[2].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[2].paraCB_stop0 = comboBox_m3_stop0;
            motorlist[2].paraCB_stop0.SelectedIndex = 1;
            motorlist[2].paraCB_stop1 = comboBox_m3_stop1;
            motorlist[2].paraCB_stop1.SelectedIndex = 0;
            motorlist[2].paraCB_level = comboBox_m3_level;
            motorlist[2].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[2].ioCB_positiveBit = checkBox_m3_IOIn_positivebit;
            motorlist[2].ioCB_nagativeBit = checkBox_m3_IOIn_nagativebit;
            motorlist[2].ioCB_stop0 = checkBox_m3_IOIn_STOP0;
            motorlist[2].ioCB_stop1 = checkBox_m3_IOIn_STOP1;

            /*motor 4 control list*/
            //base
            motorlist[3].baseCB_ID = checkBox_m4;
            motorlist[3].baseTB_destination = textBox_m4_destination;
            motorlist[3].baseTB_initSpeed = textBox_m4_initspeed;
            motorlist[3].baseTB_speed = textBox_m4_speed;
            motorlist[3].baseTB_speedUp = textBox_m4_speedup;
            //para
            motorlist[3].paraCB_pulse = comboBox_m4_pulse;
            motorlist[3].paraCB_pulse.SelectedIndex = 1;
            motorlist[3].paraCB_positiveBit = comboBox_m4_positivebit;
            motorlist[3].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[3].paraCB_nagativeBit = comboBox_m4_nagativebit;
            motorlist[3].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[3].paraCB_stop0 = comboBox_m4_stop0;
            motorlist[3].paraCB_stop0.SelectedIndex = 1;
            motorlist[3].paraCB_stop1 = comboBox_m4_stop1;
            motorlist[3].paraCB_stop1.SelectedIndex = 0;
            motorlist[3].paraCB_level = comboBox_m4_level;
            motorlist[3].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[3].ioCB_positiveBit = checkBox_m4_IOIn_positivebit;
            motorlist[3].ioCB_nagativeBit = checkBox_m4_IOIn_nagativebit;
            motorlist[3].ioCB_stop0 = checkBox_m4_IOIn_STOP0;
            motorlist[3].ioCB_stop1 = checkBox_m4_IOIn_STOP1;

            /*motor 5 control list*/
            //base
            motorlist[4].baseCB_ID = checkBox_m5;
            motorlist[4].baseTB_destination = textBox_m5_destination;
            motorlist[4].baseTB_initSpeed = textBox_m5_initspeed;
            motorlist[4].baseTB_speed = textBox_m5_speed;
            motorlist[4].baseTB_speedUp = textBox_m5_speedup;
            //para
            motorlist[4].paraCB_pulse = comboBox_m5_pulse;
            motorlist[4].paraCB_pulse.SelectedIndex = 1;
            motorlist[4].paraCB_positiveBit = comboBox_m5_positivebit;
            motorlist[4].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[4].paraCB_nagativeBit = comboBox_m5_nagativebit;
            motorlist[4].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[4].paraCB_stop0 = comboBox_m5_stop0;
            motorlist[4].paraCB_stop0.SelectedIndex = 1;
            motorlist[4].paraCB_stop1 = comboBox_m5_stop1;
            motorlist[4].paraCB_stop1.SelectedIndex = 0;
            motorlist[4].paraCB_level = comboBox_m5_level;
            motorlist[4].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[4].ioCB_positiveBit = checkBox_m5_IOIn_positivebit;
            motorlist[4].ioCB_nagativeBit = checkBox_m5_IOIn_nagativebit;
            motorlist[4].ioCB_stop0 = checkBox_m5_IOIn_STOP0;
            motorlist[4].ioCB_stop1 = checkBox_m5_IOIn_STOP1;

            /*motor 6 control list*/
            //base
            motorlist[5].baseCB_ID = checkBox_m6;
            motorlist[5].baseTB_destination = textBox_m6_destination;
            motorlist[5].baseTB_initSpeed = textBox_m6_initspeed;
            motorlist[5].baseTB_speed = textBox_m6_speed;
            motorlist[5].baseTB_speedUp = textBox_m6_speedup;
            //para
            motorlist[5].paraCB_pulse = comboBox_m6_pulse;
            motorlist[5].paraCB_pulse.SelectedIndex = 1;
            motorlist[5].paraCB_positiveBit = comboBox_m6_positivebit;
            motorlist[5].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[5].paraCB_nagativeBit = comboBox_m6_nagativebit;
            motorlist[5].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[5].paraCB_stop0 = comboBox_m6_stop0;
            motorlist[5].paraCB_stop0.SelectedIndex = 1;
            motorlist[5].paraCB_stop1 = comboBox_m6_stop1;
            motorlist[5].paraCB_stop1.SelectedIndex = 0;
            motorlist[5].paraCB_level = comboBox_m6_level;
            motorlist[5].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[5].ioCB_positiveBit = checkBox_m6_IOIn_positivebit;
            motorlist[5].ioCB_nagativeBit = checkBox_m6_IOIn_nagativebit;
            motorlist[5].ioCB_stop0 = checkBox_m6_IOIn_STOP0;
            motorlist[5].ioCB_stop1 = checkBox_m6_IOIn_STOP1;

            /*motor 7 control list*/
            //base
            motorlist[6].baseCB_ID = checkBox_m7;
            motorlist[6].baseTB_destination = textBox_m7_destination;
            motorlist[6].baseTB_initSpeed = textBox_m7_initspeed;
            motorlist[6].baseTB_speed = textBox_m7_speed;
            motorlist[6].baseTB_speedUp = textBox_m7_speedup;
            //para
            motorlist[6].paraCB_pulse = comboBox_m7_pulse;
            motorlist[6].paraCB_pulse.SelectedIndex = 1;
            motorlist[6].paraCB_positiveBit = comboBox_m7_positivebit;
            motorlist[6].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[6].paraCB_nagativeBit = comboBox_m7_nagativebit;
            motorlist[6].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[6].paraCB_stop0 = comboBox_m7_stop0;
            motorlist[6].paraCB_stop0.SelectedIndex = 1;
            motorlist[6].paraCB_stop1 = comboBox_m7_stop1;
            motorlist[6].paraCB_stop1.SelectedIndex = 0;
            motorlist[6].paraCB_level = comboBox_m7_level;
            motorlist[6].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[6].ioCB_positiveBit = checkBox_m7_IOIn_positivebit;
            motorlist[6].ioCB_nagativeBit = checkBox_m7_IOIn_nagativebit;
            motorlist[6].ioCB_stop0 = checkBox_m7_IOIn_STOP0;
            motorlist[6].ioCB_stop1 = checkBox_m7_IOIn_STOP1;

            /*motor 8 control list*/
            //base
            motorlist[7].baseCB_ID = checkBox_m8;
            motorlist[7].baseTB_destination = textBox_m8_destination;
            motorlist[7].baseTB_initSpeed = textBox_m8_initspeed;
            motorlist[7].baseTB_speed = textBox_m8_speed;
            motorlist[7].baseTB_speedUp = textBox_m8_speedup;
            //para
            motorlist[7].paraCB_pulse = comboBox_m8_pulse;
            motorlist[7].paraCB_pulse.SelectedIndex = 1;
            motorlist[7].paraCB_positiveBit = comboBox_m8_positivebit;
            motorlist[7].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[7].paraCB_nagativeBit = comboBox_m8_nagativebit;
            motorlist[7].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[7].paraCB_stop0 = comboBox_m8_stop0;
            motorlist[7].paraCB_stop0.SelectedIndex = 1;
            motorlist[7].paraCB_stop1 = comboBox_m8_stop1;
            motorlist[7].paraCB_stop1.SelectedIndex = 0;
            motorlist[7].paraCB_level = comboBox_m8_level;
            motorlist[7].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[7].ioCB_positiveBit = checkBox_m8_IOIn_positivebit;
            motorlist[7].ioCB_nagativeBit = checkBox_m8_IOIn_nagativebit;
            motorlist[7].ioCB_stop0 = checkBox_m8_IOIn_STOP0;
            motorlist[7].ioCB_stop1 = checkBox_m8_IOIn_STOP1;

            /*motor 9 control list*/
            //base
            motorlist[8].baseCB_ID = checkBox_m9;
            motorlist[8].baseTB_destination = textBox_m9_destination;
            motorlist[8].baseTB_initSpeed = textBox_m9_initspeed;
            motorlist[8].baseTB_speed = textBox_m9_speed;
            motorlist[8].baseTB_speedUp = textBox_m9_speedup;
            //para
            motorlist[8].paraCB_pulse = comboBox_m9_pulse;
            motorlist[8].paraCB_pulse.SelectedIndex = 1;
            motorlist[8].paraCB_positiveBit = comboBox_m9_positivebit;
            motorlist[8].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[8].paraCB_nagativeBit = comboBox_m9_nagativebit;
            motorlist[8].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[8].paraCB_stop0 = comboBox_m9_stop0;
            motorlist[8].paraCB_stop0.SelectedIndex = 1;
            motorlist[8].paraCB_stop1 = comboBox_m9_stop1;
            motorlist[8].paraCB_stop1.SelectedIndex = 0;
            motorlist[8].paraCB_level = comboBox_m9_level;
            motorlist[8].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[8].ioCB_positiveBit = checkBox_m9_IOIn_positivebit;
            motorlist[8].ioCB_nagativeBit = checkBox_m9_IOIn_nagativebit;
            motorlist[8].ioCB_stop0 = checkBox_m9_IOIn_STOP0;
            motorlist[8].ioCB_stop1 = checkBox_m9_IOIn_STOP1;

            /*motor 10 control list*/
            //base
            motorlist[9].baseCB_ID = checkBox_m10;
            motorlist[9].baseTB_destination = textBox_m10_destination;
            motorlist[9].baseTB_initSpeed = textBox_m10_initspeed;
            motorlist[9].baseTB_speed = textBox_m10_speed;
            motorlist[9].baseTB_speedUp = textBox_m10_speedup;
            //para
            motorlist[9].paraCB_pulse = comboBox_m10_pulse;
            motorlist[9].paraCB_pulse.SelectedIndex = 1;
            motorlist[9].paraCB_positiveBit = comboBox_m10_positivebit;
            motorlist[9].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[9].paraCB_nagativeBit = comboBox_m10_nagativebit;
            motorlist[9].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[9].paraCB_stop0 = comboBox_m10_stop0;
            motorlist[9].paraCB_stop0.SelectedIndex = 1;
            motorlist[9].paraCB_stop1 = comboBox_m10_stop1;
            motorlist[9].paraCB_stop1.SelectedIndex = 0;
            motorlist[9].paraCB_level = comboBox_m10_level;
            motorlist[9].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[9].ioCB_positiveBit = checkBox_m10_IOIn_positivebit;
            motorlist[9].ioCB_nagativeBit = checkBox_m10_IOIn_nagativebit;
            motorlist[9].ioCB_stop0 = checkBox_m10_IOIn_STOP0;
            motorlist[9].ioCB_stop1 = checkBox_m10_IOIn_STOP1;

            /*motor 11 control list*/
            //base
            motorlist[10].baseCB_ID = checkBox_m11;
            motorlist[10].baseTB_destination = textBox_m11_destination;
            motorlist[10].baseTB_initSpeed = textBox_m11_initspeed;
            motorlist[10].baseTB_speed = textBox_m11_speed;
            motorlist[10].baseTB_speedUp = textBox_m11_speedup;
            //para
            motorlist[10].paraCB_pulse = comboBox_m11_pulse;
            motorlist[10].paraCB_pulse.SelectedIndex = 1;
            motorlist[10].paraCB_positiveBit = comboBox_m11_positivebit;
            motorlist[10].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[10].paraCB_nagativeBit = comboBox_m11_nagativebit;
            motorlist[10].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[10].paraCB_stop0 = comboBox_m11_stop0;
            motorlist[10].paraCB_stop0.SelectedIndex = 1;
            motorlist[10].paraCB_stop1 = comboBox_m11_stop1;
            motorlist[10].paraCB_stop1.SelectedIndex = 0;
            motorlist[10].paraCB_level = comboBox_m11_level;
            motorlist[10].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[10].ioCB_positiveBit = checkBox_m11_IOIn_positivebit;
            motorlist[10].ioCB_nagativeBit = checkBox_m11_IOIn_nagativebit;
            motorlist[10].ioCB_stop0 = checkBox_m11_IOIn_STOP0;
            motorlist[10].ioCB_stop1 = checkBox_m11_IOIn_STOP1;

            /*motor 12 control list*/
            //base
            motorlist[11].baseCB_ID = checkBox_m12;
            motorlist[11].baseTB_destination = textBox_m12_destination;
            motorlist[11].baseTB_initSpeed = textBox_m12_initspeed;
            motorlist[11].baseTB_speed = textBox_m12_speed;
            motorlist[11].baseTB_speedUp = textBox_m12_speedup;
            //para
            motorlist[11].paraCB_pulse = comboBox_m12_pulse;
            motorlist[11].paraCB_pulse.SelectedIndex = 1;
            motorlist[11].paraCB_positiveBit = comboBox_m12_positivebit;
            motorlist[11].paraCB_positiveBit.SelectedIndex = 0;
            motorlist[11].paraCB_nagativeBit = comboBox_m12_nagativebit;
            motorlist[11].paraCB_nagativeBit.SelectedIndex = 0;
            motorlist[11].paraCB_stop0 = comboBox_m12_stop0;
            motorlist[11].paraCB_stop0.SelectedIndex = 1;
            motorlist[11].paraCB_stop1 = comboBox_m12_stop1;
            motorlist[11].paraCB_stop1.SelectedIndex = 0;
            motorlist[11].paraCB_level = comboBox_m12_level;
            motorlist[11].paraCB_level.SelectedIndex = 0;
            //IO
            motorlist[11].ioCB_positiveBit = checkBox_m12_IOIn_positivebit;
            motorlist[11].ioCB_nagativeBit = checkBox_m12_IOIn_nagativebit;
            motorlist[11].ioCB_stop0 = checkBox_m12_IOIn_STOP0;
            motorlist[11].ioCB_stop1 = checkBox_m12_IOIn_STOP1;
        }

        private void combobox_default_selected()
        {
            for (int i = 0; i < MOTOR_NUMBER; i++)
            {
                motorlist[i].paraCB_pulse.SelectedIndex = 1;
                motorlist[i].paraCB_positiveBit.SelectedIndex = 0;
                motorlist[i].paraCB_nagativeBit.SelectedIndex = 0;
                motorlist[i].paraCB_stop0.SelectedIndex = 1;
                motorlist[i].paraCB_stop1.SelectedIndex = 0;
                motorlist[i].paraCB_level.SelectedIndex = 0;
            }
        }

        private void button_paraReset_Click(object sender, EventArgs e)
        {
            combobox_default_selected();
        }

        private void UartInit()
        {
            ScanSerialPort();

            comboBox_BaudRate.SelectedIndex = 0;
            comboBox_ParityBit.SelectedIndex = 0;
            comboBox_stop.SelectedIndex = 0;

            _MyPort = new SerialPort();
        }

        private void ScanSerialPort()
        {
            string[] str = SerialPort.GetPortNames();
            comboBox_serialport.Items.Clear();
            if (str == null)
            {
                SetCmdText("没有检测到串口");
                return;
            }
            //添加串口项目  
            foreach (string s in System.IO.Ports.SerialPort.GetPortNames())
            {
                comboBox_serialport.Items.Add(s);
            }
            comboBox_serialport.SelectedIndex = comboBox_serialport.Items.Count - 1;
            return;
        }

        private void SetCmdText(string text)
        {
            textBox_cmd.Text += text.Replace("\n", "\n>");
            //textBox_cmd.Text += "\r\n>";
        }

        private void button_scan_Click(object sender, EventArgs e)
        {
            ScanSerialPort();
        }

        private void button_openSP_Click(object sender, EventArgs e)
        {
            if (button_openSP.Text == "打开串口")
            {
                try
                {
                    if (_MyPort.IsOpen)
                    {
                        SetCmdText("提示：串口已打开！");
                        return;
                    }
                    if (!SetSerialPort(_MyPort))
                    {
                        return;
                    }
                    _MyPort.DataReceived += new SerialDataReceivedEventHandler(SPort_DataReceive);

                    _MyPort.Open();

                    button_openSP.Text = "关闭串口";
                }
                catch (Exception ex)
                {
                    SetCmdText(string.Format("出错提示：{0}", ex.Message));
                    return;
                }
            }
            else
            {
                _MyPort.Close();
                button_openSP.Text = "打开串口";
            }
            return;
        }

        private bool SetSerialPort(SerialPort port)
        {
            try
            {
                port.PortName = comboBox_serialport.Text;
                port.BaudRate = Convert.ToInt32(comboBox_BaudRate.Text);
                switch (comboBox_ParityBit.SelectedIndex)
                {
                    case 0:
                        port.Parity = Parity.None;
                        break;
                    default:
                        port.Parity = Parity.None;
                        break;
                }

                switch (comboBox_stop.SelectedIndex)
                {
                    case 0:
                        port.StopBits = StopBits.One;
                        break;
                    default:
                        port.StopBits = StopBits.One;
                        break;
                }
            }
            catch (Exception ex)
            {
                SetCmdText(String.Format("出错提示：", ex.Message));
                return false;
            }
            return true;
        }

        private void SPort_DataReceive(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string currentline = "";
                //循环接收串口中的数据
                while (_MyPort.BytesToRead > 0)
                {
                    char ch = (char)_MyPort.ReadByte();
                    currentline += ch.ToString();
                }
                //在这里对接收到的数据进行显示
                //如果不在窗体加载的事件里写上：Form.CheckForIllegalCrossThreadCalls = false; 就会报错）
                //Dispatcher.Invoke(System.Windows.Threading.DispatcherPriority.SystemIdle, new DelegateSetCmdText(SetCmdText), currentline);
                textBox_cmd.Invoke(new DelegateSetCmdText(SetCmdText), /*currentline.Replace("\n", "\r\n")*/currentline);
            }
            catch (Exception ex)
            {
                //Console.WriteLine(ex.Message.ToString());
                textBox_cmd.Invoke(new DelegateSetCmdText(SetCmdText), ex.Message.ToString());
            }
        }

        public void SPort_SendData(string str_cmd)
        {
            try
            {
                //串口只能读取ASCII码或者进制数（1，2，3.....的进制，一般是16进制）
                byte[] WriteBuffer = Encoding.ASCII.GetBytes(str_cmd);
                //将数据缓冲区的数据写入到串口端口
                _MyPort.Write(WriteBuffer, 0, WriteBuffer.Length);
            }
            catch (Exception ex)
            {
                SetCmdText(String.Format("错误提示：{0}", ex.Message));
                return;
            }
        }

        public void SendCmd()
        {
            string[] strArray = textBox_cmd.Text.Split('>');
            string cmd = strArray[strArray.Count() - 1] + "\r\n";
            SPort_SendData(cmd);
        }

        private void textBox_cmd_KeyDown(object sender, KeyEventArgs e)
        {
            if (textBox_cmd.Text.Substring(textBox_cmd.SelectionStart - 1, 1) == ">")
            {
                if (e.KeyValue == 8)
                {
                    e.SuppressKeyPress = true;
                    return;
                }
            }
            if (e.KeyValue == 13)
            {
                SendCmd();
                textBox_cmd.Text += "\r\n>";
                e.SuppressKeyPress = true;
                return;
            }
        }

        private void textBox_cmd_MouseClick(object sender, MouseEventArgs e)
        {
            textBox_cmd.SelectionStart = textBox_cmd.Text.Length;
            textBox_cmd.ScrollToCaret();
        }

        private void textBox_cmd_TextChanged(object sender, EventArgs e)
        {
            textBox_cmd.SelectionStart = textBox_cmd.Text.Length;
            textBox_cmd.ScrollToCaret();
        }

        private bool IsUartOpen()
        {
            if (_MyPort.IsOpen)
            {
                return true;
            }
            MessageBox.Show("串口没有打开，无法通信！","ERROR");
            return false;
        }

        private void button_motor_start_Click(object sender, EventArgs e)
        {
            if(!IsUartOpen())
            {
                return;
            }
            for (int i = 0; i < MOTOR_NUMBER; i++)
            {
                if (!motorlist[i].baseCB_ID.Checked)
                    continue;
                motor_run_cmd(i);

            }
        }

        private void motor_run_cmd(int index)
        {
            string str_err;
            string str_cmd;
            UInt16 uclockwise;
            if (index < 0 || index >= MOTOR_NUMBER)
            {
                str_err = String.Format("非法的电机号 %d", index + 1);
                MessageBox.Show(str_err, "ERROR");
                return;
            }
            if(motorlist[index].baseTB_destination.Text == "")
            {
                str_err = String.Format("电机%d的目标位置没有设置值", index + 1);
                MessageBox.Show(str_err, "ERROR");
                return;
            }
            if (motorlist[index].baseTB_initSpeed.Text == "")
            {
                str_err = String.Format("电机%d的初始速度没有设置值", index + 1);
                MessageBox.Show(str_err, "ERROR");
                return;
            }
            if (motorlist[index].baseTB_speed.Text == "")
            {
                str_err = String.Format("电机%d的速度没有设置值", index + 1);
                MessageBox.Show(str_err, "ERROR");
                return;
            }
            if (motorlist[index].baseTB_speedUp.Text == "")
            {
                str_err = String.Format("电机%d的加速度没有设置值", index + 1);
                MessageBox.Show(str_err, "ERROR");
                return;
            }
            if(radioButton_positive.Checked)
            {
                uclockwise = 1;
            }
            else
            {
                uclockwise = 0;
            }

            str_cmd = String.Format("CMD_RUN#ID@{0}#DESTI@{1}#INITSP@{2}#SP@{3}#SPUP@{4}#CLKW@{5}\r\n",
                                        index+1,
                                        Convert.ToInt32(motorlist[index].baseTB_destination.Text),
                                        Convert.ToInt32(motorlist[index].baseTB_initSpeed.Text),
                                        Convert.ToInt32(motorlist[index].baseTB_speed.Text),
                                        Convert.ToInt32(motorlist[index].baseTB_speedUp.Text),
                                        uclockwise);
            SPort_SendData(str_cmd);
            return;
        }

        private void button_paraSet_Click(object sender, EventArgs e)
        {
            string str_cmd;
            if (!IsUartOpen())
            {
                return;
            }
            for (int i = 0; i < MOTOR_NUMBER; i++)
            {
                str_cmd = String.Format("CMD_SET#ID@{0}@PULSE@{1}#LMTP@{2}#LMTN@{3}#STOP0@{4}#STOP1@{5}#LEVEL@{6}\r\n",
                                            i + 1,
                                            motorlist[i].paraCB_pulse.SelectedIndex,
                                            motorlist[i].paraCB_positiveBit.SelectedIndex,
                                            motorlist[i].paraCB_nagativeBit.SelectedIndex,
                                            motorlist[i].paraCB_stop0.SelectedIndex,
                                            motorlist[i].paraCB_stop1.SelectedIndex,
                                            motorlist[i].paraCB_level.SelectedIndex);
                SPort_SendData(str_cmd);
            }
            return;
        }

        private void button_motor_stop_Click(object sender, EventArgs e)
        {
            string str_cmd;
            if (!IsUartOpen())
            {
                return;
            }
            for (int i = 0; i < MOTOR_NUMBER; i++)
            {
                if (!motorlist[i].baseCB_ID.Checked)
                    continue;
                str_cmd = String.Format("CMD_STOP#ID@{0}\r\n", i + 1);
                SPort_SendData(str_cmd);
            }
        }

        private void button_urat_clear_Click(object sender, EventArgs e)
        {
            textBox_cmd.Text = ">";
        }

        private void button_IO_OUTALL_Click(object sender, EventArgs e)
        {
            string str_cmd;
            if (!IsUartOpen())
            {
                return;
            }
            for (int i = 0; i < RELAY_NUMBER; i++)
            {
                str_cmd = String.Format("CMD_RELAY#ID@{0}#BIT@{1}\r\n", i + 1, 0);
                SPort_SendData(str_cmd);
            }
        }

        private void button_IO_OUTCLOSE_Click(object sender, EventArgs e)
        {
            string str_cmd;
            if (!IsUartOpen())
            {
                return;
            }
            for (int i = 0; i < RELAY_NUMBER; i++)
            {
                str_cmd = String.Format("CMD_RELAY#ID@{0}#BIT@{1}\r\n", i + 1, 1);
                SPort_SendData(str_cmd);
            }
        }

        private void button_IO_out_Click(object sender, EventArgs e)
        {
            string str_cmd;
            Button button = (Button)sender;
            if (!IsUartOpen())
            {
                return;
            }
            if(button.Text == "OFF")
            {
                str_cmd = String.Format("CMD_RELAY#ID@{0}#BIT@0\r\n", button.Tag);
                SPort_SendData(str_cmd);
                button.Text = "ON";
            }
            else
            {
                str_cmd = String.Format("CMD_RELAY#ID@{0}#BIT@1\r\n", button.Tag);
                SPort_SendData(str_cmd);
                button.Text = "OFF";
            }
        }
    }

    public struct MotorControl
    {
        /*base set*/
        public CheckBox baseCB_ID;
        public TextBox baseTB_destination;
        public TextBox baseTB_initSpeed;
        public TextBox baseTB_speed;
        public TextBox baseTB_speedUp;

        /*show result*/
        public Label showL_timePosition;
        public Label showL_finalPosition;
        public Label showL_speed;
        public Label showL_positiveBit;
        public Label showL_nagativeBit;
        public Label showL_stop0;
        public Label showL_stop1;

        /*para set*/
        public ComboBox paraCB_pulse;
        public ComboBox paraCB_positiveBit;
        public ComboBox paraCB_nagativeBit;
        public ComboBox paraCB_stop0;
        public ComboBox paraCB_stop1;
        public ComboBox paraCB_level;

        /*IO check*/
        public CheckBox ioCB_positiveBit;
        public CheckBox ioCB_nagativeBit;
        public CheckBox ioCB_stop0;
        public CheckBox ioCB_stop1;
    }
}
