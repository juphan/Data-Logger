#pragma once

namespace DataLogger {

	using namespace System;
	using namespace System::IO; // Added for StreamWriter
	using namespace System::IO::Ports; // Added for Serial Ports
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			//TODO: Add the constructor code here

			// Visual components
			btnStop->Visible = false; // Hide stop button
			btnDiscon->Enabled = false;
			btnStart->Enabled = false;

			// Get all available COM ports
			scanCOMs->PerformClick();

			// Serial Data event handler
			SerialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm::DataReceived);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ gbConnect;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ gbTimer;
	private: System::Windows::Forms::Button^ btnStop;
	private: System::Windows::Forms::Button^ btnStart;
	private: System::Windows::Forms::Button^ btnDiscon;
	private: System::Windows::Forms::Button^ btnConnect;
	private: System::Windows::Forms::Label^ colon2;
	private: System::Windows::Forms::Label^ colon1;
	private: System::Windows::Forms::Label^ secs;
	private: System::Windows::Forms::Label^ mins;
	private: System::Windows::Forms::Label^ hours;
	private: System::IO::Ports::SerialPort^ SerialPort1;

	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ scanCOMs;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->gbConnect = (gcnew System::Windows::Forms::GroupBox());
			this->scanCOMs = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->btnDiscon = (gcnew System::Windows::Forms::Button());
			this->btnConnect = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->gbTimer = (gcnew System::Windows::Forms::GroupBox());
			this->colon2 = (gcnew System::Windows::Forms::Label());
			this->colon1 = (gcnew System::Windows::Forms::Label());
			this->secs = (gcnew System::Windows::Forms::Label());
			this->mins = (gcnew System::Windows::Forms::Label());
			this->hours = (gcnew System::Windows::Forms::Label());
			this->SerialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->gbConnect->SuspendLayout();
			this->gbTimer->SuspendLayout();
			this->SuspendLayout();
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(30, 85);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(393, 56);
			this->comboBox1->TabIndex = 0;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"115200", L"9600" });
			this->comboBox2->Location = System::Drawing::Point(661, 84);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(393, 56);
			this->comboBox2->TabIndex = 1;
			// 
			// gbConnect
			// 
			this->gbConnect->Controls->Add(this->scanCOMs);
			this->gbConnect->Controls->Add(this->btnStop);
			this->gbConnect->Controls->Add(this->btnStart);
			this->gbConnect->Controls->Add(this->btnDiscon);
			this->gbConnect->Controls->Add(this->btnConnect);
			this->gbConnect->Controls->Add(this->textBox1);
			this->gbConnect->Controls->Add(this->label1);
			this->gbConnect->Controls->Add(this->comboBox1);
			this->gbConnect->Controls->Add(this->comboBox2);
			this->gbConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbConnect->Location = System::Drawing::Point(34, 31);
			this->gbConnect->Name = L"gbConnect";
			this->gbConnect->Size = System::Drawing::Size(1715, 346);
			this->gbConnect->TabIndex = 2;
			this->gbConnect->TabStop = false;
			this->gbConnect->Text = L"Connection Settings";
			// 
			// scanCOMs
			// 
			this->scanCOMs->Location = System::Drawing::Point(442, 84);
			this->scanCOMs->Name = L"scanCOMs";
			this->scanCOMs->Size = System::Drawing::Size(171, 57);
			this->scanCOMs->TabIndex = 8;
			this->scanCOMs->Text = L"SCAN";
			this->scanCOMs->UseVisualStyleBackColor = true;
			this->scanCOMs->Click += gcnew System::EventHandler(this, &MyForm::scanCOMs_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(1116, 222);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(540, 85);
			this->btnStop->TabIndex = 7;
			this->btnStop->Text = L"Stop Recording";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &MyForm::btnStop_Click);
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(1116, 222);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(540, 85);
			this->btnStart->TabIndex = 6;
			this->btnStart->Text = L"Start Recording";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &MyForm::btnStart_Click);
			// 
			// btnDiscon
			// 
			this->btnDiscon->Location = System::Drawing::Point(1391, 86);
			this->btnDiscon->Name = L"btnDiscon";
			this->btnDiscon->Size = System::Drawing::Size(265, 85);
			this->btnDiscon->TabIndex = 5;
			this->btnDiscon->Text = L"Disconnect";
			this->btnDiscon->UseVisualStyleBackColor = true;
			this->btnDiscon->Click += gcnew System::EventHandler(this, &MyForm::btnDiscon_Click);
			// 
			// btnConnect
			// 
			this->btnConnect->Location = System::Drawing::Point(1116, 85);
			this->btnConnect->Name = L"btnConnect";
			this->btnConnect->Size = System::Drawing::Size(222, 85);
			this->btnConnect->TabIndex = 4;
			this->btnConnect->Text = L"Connect";
			this->btnConnect->UseVisualStyleBackColor = true;
			this->btnConnect->Click += gcnew System::EventHandler(this, &MyForm::btnConnect_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(30, 252);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(1024, 55);
			this->textBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 180);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(364, 48);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Output File Name";
			// 
			// gbTimer
			// 
			this->gbTimer->Controls->Add(this->colon2);
			this->gbTimer->Controls->Add(this->colon1);
			this->gbTimer->Controls->Add(this->secs);
			this->gbTimer->Controls->Add(this->mins);
			this->gbTimer->Controls->Add(this->hours);
			this->gbTimer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gbTimer->Location = System::Drawing::Point(34, 423);
			this->gbTimer->Name = L"gbTimer";
			this->gbTimer->Size = System::Drawing::Size(1715, 346);
			this->gbTimer->TabIndex = 3;
			this->gbTimer->TabStop = false;
			this->gbTimer->Text = L"Timer";
			// 
			// colon2
			// 
			this->colon2->AutoSize = true;
			this->colon2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colon2->Location = System::Drawing::Point(972, 92);
			this->colon2->Name = L"colon2";
			this->colon2->Size = System::Drawing::Size(110, 163);
			this->colon2->TabIndex = 8;
			this->colon2->Text = L":";
			// 
			// colon1
			// 
			this->colon1->AutoSize = true;
			this->colon1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->colon1->Location = System::Drawing::Point(619, 92);
			this->colon1->Name = L"colon1";
			this->colon1->Size = System::Drawing::Size(110, 163);
			this->colon1->TabIndex = 7;
			this->colon1->Text = L":";
			// 
			// secs
			// 
			this->secs->AutoSize = true;
			this->secs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->secs->Location = System::Drawing::Point(1088, 107);
			this->secs->Name = L"secs";
			this->secs->Size = System::Drawing::Size(231, 163);
			this->secs->TabIndex = 6;
			this->secs->Text = L"00";
			// 
			// mins
			// 
			this->mins->AutoSize = true;
			this->mins->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mins->Location = System::Drawing::Point(735, 107);
			this->mins->Name = L"mins";
			this->mins->Size = System::Drawing::Size(231, 163);
			this->mins->TabIndex = 5;
			this->mins->Text = L"00";
			// 
			// hours
			// 
			this->hours->AutoSize = true;
			this->hours->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hours->Location = System::Drawing::Point(387, 107);
			this->hours->Name = L"hours";
			this->hours->Size = System::Drawing::Size(231, 163);
			this->hours->TabIndex = 4;
			this->hours->Text = L"00";
			// 
			// SerialPort1
			// 
			this->SerialPort1->BaudRate = 115200;
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(34, 813);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(1715, 238);
			this->textBox2->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(14, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1786, 1080);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->gbTimer);
			this->Controls->Add(this->gbConnect);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Data Logger";
			this->gbConnect->ResumeLayout(false);
			this->gbConnect->PerformLayout();
			this->gbTimer->ResumeLayout(false);
			this->gbTimer->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

// File write variables
String^ filePath = System::Environment::GetFolderPath(Environment::SpecialFolder::DesktopDirectory) + "\\DataSync_JP\\"; // File path to Desktop folder

StreamWriter^ sw;
bool isLogging = false;
String^ temp;

// Timer
int hour = 0;
int min = 0;
int sec = 0;

private: System::Void startTimer() {
	// Reset timer values
	hour = 0;
	min = 0;
	sec = 0;

	// Reset display values
	hours->Text = "00";
	mins->Text = "00";
	secs->Text = "00";

	// Start Timer1
	timer1->Enabled = true;
	timer1->Start();
}

// Timer1 tick event handler
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	increaseSecs();

	// Update display
	hours->Text = hour.ToString("00");
	mins->Text = min.ToString("00");
	secs->Text = sec.ToString("00");
}

// Increase secs in display
private: System::Void increaseSecs() {
	if (sec == 59) {
		sec = 0;
		increaseMins();
	}
	else {
		++sec;
	}
}

// Increase mins in display
private: System::Void increaseMins() {
	if (min == 59) {
		min = 0;
		increaseHours();
	}
	else {
		++min;
	}
}

// Increase hours in display
private: System::Void increaseHours() {
	++hour;
}

// Check available COM ports
private: System::Void scanCOMs_Click(System::Object^ sender, System::EventArgs^ e) {
	array<String^>^ coms = SerialPort::GetPortNames();
	this->comboBox1->Items->Clear();
	this->comboBox1->Items->AddRange(coms);
}

// Start recording data 
private: System::Void btnStart_Click(System::Object^ sender, System::EventArgs^ e) {
	// Determine output file path
	String^ path;
	if (textBox1->Text == String::Empty) {
		path = filePath + "DefaultOutput.csv";
	}
	else {
		path = filePath + textBox1->Text + ".csv";
	}

	// Set filepath of StreamWriter
	sw = gcnew StreamWriter(path);
	isLogging = true;

	// Start display timer
	timer1->Interval = 1000; // Timer1 ticks every 1000ms (1s)
	btnStart->Visible = false;
	btnStop->Visible = true;
	startTimer();
}

// Stop recording data
private: System::Void btnStop_Click(System::Object^ sender, System::EventArgs^ e) {
	// Close output
	isLogging = false;
	sw->Close();
	
	// Stop display timer
	timer1->Enabled = false;
	btnStart->Visible = true;
	btnStop->Visible = false;
}

// Connect to SerialPort1
private: System::Void btnConnect_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->Text == String::Empty || comboBox2->Text == String::Empty) { // Check if COM port settings are selected
		textBox2->Text = "ERROR: Please select valid COM Port settings!";
	}
	else {
		try {
			if (!SerialPort1->IsOpen) { // Check if serial port hasn't been opened yet
				SerialPort1->PortName = comboBox1->Text; // Set COM port
				SerialPort1->BaudRate = System::Convert::ToInt32(comboBox2->Text); // Set baud rate
				SerialPort1->Open(); // Open serial port
				btnConnect->Enabled = false; // Block button press afterwards
				btnDiscon->Enabled = true; // Open disconnect button
				btnStart->Enabled = true; // Open "Start Logging" button
			}
			else {
				textBox2->Text = "ERROR: Port cannot be opened!";
			}
		}
		catch (...) {
			textBox2->Text = "ERROR: Unauthorized access to the COM port!";
		}
	}
}

// Disconnect from SerialPort1
private: System::Void btnDiscon_Click(System::Object^ sender, System::EventArgs^ e) {
	SerialPort1->Close();
	btnConnect->Enabled = true;
	btnDiscon->Enabled = false;
	btnStart->Enabled = false;
}

// Listen to SerialPort1
private: void DataReceived(Object^ sender, SerialDataReceivedEventArgs^ e) {
	if (isLogging) {
		try {
			temp = SerialPort1->ReadLine();
			if (isLogging)
				sw->WriteLine(temp);
		}
		catch (...) {
			MessageBox::Show("ERROR: Issues with reading serial port data!");
		}
	}
	else {
		try {
			SerialPort1->DiscardInBuffer();
		}
		catch (...) {
			MessageBox::Show("ERROR: Issues with discarding serial port data!");
		}
	}
}

};
}
