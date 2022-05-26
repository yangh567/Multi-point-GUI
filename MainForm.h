#pragma once

#include <string> 
#include <PBD_Engine_Prerequisites.h>
#include <PBD_Engine_CWrapper.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <HapticShape.h>
#include <fstream>
#include <variant>
#include <string>
#include <msclr\marshal_cppstd.h>

//#include "MicroTimer.h"
#define _USE_MATH_DEFINES
#include <math.h>

using std::to_string;

int curShape = 0;
int curFrequencyBase = 1; //Frequencies must be a divider of 10000 (FPS)
int curNumPoints = 0;
int curNumSamples = 100; // Zero for original speed model (one sample per update)
// The diameter of shapes or single path of the line(the line do have 2 paths, forward and backward)
float side1 = 0.0636943f;

std::vector<std::vector<int>> freq_tests
{
	// BaseFreq. numPoints, speed, drawing frequency, shape
};

int freq_test_Index = 0;


std::vector<std::vector<int>> speed_tests
{
	/*{14,4},
	{18,3},
	{3,4},
	{56,1},
	{28,2},*/
};

int speed_test_Index = 0;

HapticShape* shapes[5] = { NULL, NULL, NULL, NULL, NULL };

PBD_PrimitiveManager_Handler  pm;
cl_uint currentPD;
cl_uint fixedAmplitude;
std::list<cl_uint> primitives;

void debugprintf(const char* msg, ...) {
	return;
	va_list _ArgList;
	__crt_va_start(_ArgList, msg);
	vprintf(msg, _ArgList);
	__crt_va_end(_ArgList);
}
void print(const char* msg) {
	wchar_t buffer[128] = { 0 };
	swprintf(buffer, _countof(buffer), L"%s\n", msg);
	OutputDebugString(buffer);
}

void declareContent(PBD_PrimitiveManager_Handler pm, float side);
void configureContent(PBD_PrimitiveManager_Handler pm, HapticShape* shape, int numPoints, int baseFrequency, int numSamples);
void destroyContent(PBD_PrimitiveManager_Handler pm);

std::ofstream responses;
std::ofstream quest_responses;
std::ofstream q_responses;

const int stimulusSeconds = 1;
int currentSeconds = 0;

namespace FirstForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ stepsControl;
	private: System::Windows::Forms::TabPage^ tabID;
	protected:

	private: System::Windows::Forms::Label^ lbWelcome;
	private: System::Windows::Forms::TextBox^ participantID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnOK;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabPage^ tabTrials;



	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::TabPage^ tabPage5;
	private: System::Windows::Forms::TabPage^ tabPage6;
	private: System::Windows::Forms::TabPage^ tabPage7;
	private: System::Windows::Forms::Button^ nextTrial;
	private: System::Windows::Forms::TrackBar^ sliderValence;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Timer^ trialTimer;
	private: System::Windows::Forms::Label^ trialLabel;
	private: System::Windows::Forms::Button^ IDConfirmButton;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::TabPage^ tabIntermediate;




	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TabPage^ tabTests;

	private: System::Windows::Forms::Label^ testLabel;



	private: System::Windows::Forms::Button^ nextTest;
	private: System::Windows::Forms::TrackBar^ sliderValenceTest;



	private: System::Windows::Forms::Timer^ testTimer;
	private: System::Windows::Forms::Panel^ trialProgress;





	private: System::ComponentModel::IContainer^ components;

	protected:













	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

	private: System::Windows::Forms::Panel^ testProgress;
		int _trialWidth;




	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;

	private: System::Windows::Forms::Button^ button9;


	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::TabPage^ tabPage1;

	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;

	private: System::Windows::Forms::TabPage^ TabGoQuest;

	private: System::Windows::Forms::TabPage^ endPage;
	private: System::Windows::Forms::Label^ goodbyLabel;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TrackBar^ sliderArousal;
	private: System::Windows::Forms::TrackBar^ sliderIntensity;
	private: System::Windows::Forms::TrackBar^ sliderIntensityTest;
	private: System::Windows::Forms::TrackBar^ sliderArousalTest;
	private: System::Windows::Forms::TabPage^ tabQuest;

	private: System::Windows::Forms::Button^ button17;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::RichTextBox^ Q2Text;

	private: System::Windows::Forms::TabPage^ tabQuest1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RichTextBox^ Q3Text;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button18;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::RadioButton^ radioButton4;
private: System::Windows::Forms::RadioButton^ radioButton3;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::RadioButton^ radioButton1;
private: System::Windows::Forms::RadioButton^ radioButton5;
private: System::Windows::Forms::RadioButton^ radioButton7;
private: System::Windows::Forms::RadioButton^ radioButton6;
private: System::Windows::Forms::RadioButton^ radioButton8;
private: System::Windows::Forms::Label^ trialArousalLevel;
private: System::Windows::Forms::Label^ trialValenceLevel;
private: System::Windows::Forms::Label^ trialIntensityLevel;
private: System::Windows::Forms::Label^ testArousalLevel;
private: System::Windows::Forms::Label^ testValenceLevel;
private: System::Windows::Forms::Label^ testIntensityLevel;









		int _testWidth;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->stepsControl = (gcnew System::Windows::Forms::TabControl());
			this->tabID = (gcnew System::Windows::Forms::TabPage());
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->participantID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->IDConfirmButton = (gcnew System::Windows::Forms::Button());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->tabPage7 = (gcnew System::Windows::Forms::TabPage());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->tabTrials = (gcnew System::Windows::Forms::TabPage());
			this->trialArousalLevel = (gcnew System::Windows::Forms::Label());
			this->trialValenceLevel = (gcnew System::Windows::Forms::Label());
			this->trialIntensityLevel = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->sliderIntensity = (gcnew System::Windows::Forms::TrackBar());
			this->sliderArousal = (gcnew System::Windows::Forms::TrackBar());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->trialProgress = (gcnew System::Windows::Forms::Panel());
			this->trialLabel = (gcnew System::Windows::Forms::Label());
			this->nextTrial = (gcnew System::Windows::Forms::Button());
			this->sliderValence = (gcnew System::Windows::Forms::TrackBar());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->tabIntermediate = (gcnew System::Windows::Forms::TabPage());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->tabTests = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->sliderIntensityTest = (gcnew System::Windows::Forms::TrackBar());
			this->sliderArousalTest = (gcnew System::Windows::Forms::TrackBar());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->testProgress = (gcnew System::Windows::Forms::Panel());
			this->nextTest = (gcnew System::Windows::Forms::Button());
			this->sliderValenceTest = (gcnew System::Windows::Forms::TrackBar());
			this->testLabel = (gcnew System::Windows::Forms::Label());
			this->TabGoQuest = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->tabQuest = (gcnew System::Windows::Forms::TabPage());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->Q2Text = (gcnew System::Windows::Forms::RichTextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->tabQuest1 = (gcnew System::Windows::Forms::TabPage());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Q3Text = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->endPage = (gcnew System::Windows::Forms::TabPage());
			this->goodbyLabel = (gcnew System::Windows::Forms::Label());
			this->trialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->testTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->testIntensityLevel = (gcnew System::Windows::Forms::Label());
			this->testValenceLevel = (gcnew System::Windows::Forms::Label());
			this->testArousalLevel = (gcnew System::Windows::Forms::Label());
			this->stepsControl->SuspendLayout();
			this->tabID->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->tabPage5->SuspendLayout();
			this->tabPage6->SuspendLayout();
			this->tabPage7->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabTrials->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderIntensity))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderArousal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderValence))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->tabIntermediate->SuspendLayout();
			this->tabTests->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderIntensityTest))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderArousalTest))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderValenceTest))->BeginInit();
			this->TabGoQuest->SuspendLayout();
			this->tabQuest->SuspendLayout();
			this->tabQuest1->SuspendLayout();
			this->endPage->SuspendLayout();
			this->SuspendLayout();
			// 
			// stepsControl
			// 
			this->stepsControl->Controls->Add(this->tabID);
			this->stepsControl->Controls->Add(this->tabPage3);
			this->stepsControl->Controls->Add(this->tabPage4);
			this->stepsControl->Controls->Add(this->tabPage5);
			this->stepsControl->Controls->Add(this->tabPage6);
			this->stepsControl->Controls->Add(this->tabPage7);
			this->stepsControl->Controls->Add(this->tabPage1);
			this->stepsControl->Controls->Add(this->tabTrials);
			this->stepsControl->Controls->Add(this->tabIntermediate);
			this->stepsControl->Controls->Add(this->tabTests);
			this->stepsControl->Controls->Add(this->TabGoQuest);
			this->stepsControl->Controls->Add(this->tabQuest);
			this->stepsControl->Controls->Add(this->tabQuest1);
			this->stepsControl->Controls->Add(this->endPage);
			this->stepsControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->stepsControl->Location = System::Drawing::Point(0, 0);
			this->stepsControl->Name = L"stepsControl";
			this->stepsControl->SelectedIndex = 0;
			this->stepsControl->Size = System::Drawing::Size(1004, 845);
			this->stepsControl->TabIndex = 0;
			this->stepsControl->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::stepsControl_SelectedIndexChanged);
			// 
			// tabID
			// 
			this->tabID->Controls->Add(this->lbWelcome);
			this->tabID->Controls->Add(this->participantID);
			this->tabID->Controls->Add(this->label1);
			this->tabID->Controls->Add(this->label2);
			this->tabID->Controls->Add(this->IDConfirmButton);
			this->tabID->Location = System::Drawing::Point(4, 34);
			this->tabID->Name = L"tabID";
			this->tabID->Padding = System::Windows::Forms::Padding(3);
			this->tabID->Size = System::Drawing::Size(996, 807);
			this->tabID->TabIndex = 0;
			this->tabID->Text = L"ID";
			this->tabID->UseVisualStyleBackColor = true;
			// 
			// lbWelcome
			// 
			this->lbWelcome->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Location = System::Drawing::Point(380, 392);
			this->lbWelcome->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(114, 25);
			this->lbWelcome->TabIndex = 17;
			this->lbWelcome->Text = L"Participant";
			// 
			// participantID
			// 
			this->participantID->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->participantID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->participantID->Location = System::Drawing::Point(385, 325);
			this->participantID->Margin = System::Windows::Forms::Padding(5);
			this->participantID->Name = L"participantID";
			this->participantID->Size = System::Drawing::Size(231, 30);
			this->participantID->TabIndex = 16;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(424, 258);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(150, 27);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Participant ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(436, 406);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 25);
			this->label2->TabIndex = 13;
			// 
			// IDConfirmButton
			// 
			this->IDConfirmButton->Location = System::Drawing::Point(402, 466);
			this->IDConfirmButton->Name = L"IDConfirmButton";
			this->IDConfirmButton->Size = System::Drawing::Size(186, 108);
			this->IDConfirmButton->TabIndex = 0;
			this->IDConfirmButton->Text = L"Confirm";
			this->IDConfirmButton->UseVisualStyleBackColor = true;
			this->IDConfirmButton->Click += gcnew System::EventHandler(this, &MainForm::IDConfirmButton_Click);
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->button2);
			this->tabPage3->Location = System::Drawing::Point(4, 34);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(996, 807);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"tabPage3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(88, 127);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(805, 96);
			this->label12->TabIndex = 3;
			this->label12->Text = L"Hello, Thank you for your participation. You will experience a total of 63 stimul"
				L"ations. We will start with 18 stimulation trials for training:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(707, 284);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(186, 108);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Next Tip";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label13);
			this->tabPage4->Controls->Add(this->button7);
			this->tabPage4->Controls->Add(this->button3);
			this->tabPage4->Location = System::Drawing::Point(4, 34);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(996, 807);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"tabPage4";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->Location = System::Drawing::Point(103, 165);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(837, 38);
			this->label13->TabIndex = 5;
			this->label13->Text = L"1. You will spend 5 seconds on each trial. (There will be a progress bar to show "
				L"the count down)";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(70, 275);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(186, 108);
			this->button7->TabIndex = 4;
			this->button7->Text = L"Previous Tip";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(717, 275);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(186, 108);
			this->button3->TabIndex = 1;
			this->button3->Text = L"Next Tip";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// tabPage5
			// 
			this->tabPage5->Controls->Add(this->label14);
			this->tabPage5->Controls->Add(this->button8);
			this->tabPage5->Controls->Add(this->button4);
			this->tabPage5->Location = System::Drawing::Point(4, 34);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(996, 807);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"tabPage5";
			this->tabPage5->UseVisualStyleBackColor = true;
			// 
			// label14
			// 
			this->label14->Location = System::Drawing::Point(124, 173);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(793, 43);
			this->label14->TabIndex = 6;
			this->label14->Text = L"2. You will need to use these trials to adjust your position. (Hand position and "
				L"gesture).";
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(73, 287);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(181, 108);
			this->button8->TabIndex = 5;
			this->button8->Text = L"Previous Tip";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MainForm::button8_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(720, 287);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(186, 108);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Next Tip";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// tabPage6
			// 
			this->tabPage6->Controls->Add(this->label15);
			this->tabPage6->Controls->Add(this->button9);
			this->tabPage6->Controls->Add(this->button5);
			this->tabPage6->Location = System::Drawing::Point(4, 34);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(996, 807);
			this->tabPage6->TabIndex = 5;
			this->tabPage6->Text = L"tabPage6";
			this->tabPage6->UseVisualStyleBackColor = true;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(185, 157);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(712, 25);
			this->label15->TabIndex = 7;
			this->label15->Text = L"3. Get familiar with the questions to be asked (As explained in the video).";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(71, 281);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(182, 108);
			this->button9->TabIndex = 6;
			this->button9->Text = L"Previous Tip";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(718, 281);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(186, 108);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Next Tip";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
			// 
			// tabPage7
			// 
			this->tabPage7->Controls->Add(this->label16);
			this->tabPage7->Controls->Add(this->button11);
			this->tabPage7->Controls->Add(this->button10);
			this->tabPage7->Location = System::Drawing::Point(4, 34);
			this->tabPage7->Name = L"tabPage7";
			this->tabPage7->Padding = System::Windows::Forms::Padding(3);
			this->tabPage7->Size = System::Drawing::Size(996, 807);
			this->tabPage7->TabIndex = 6;
			this->tabPage7->Text = L"tabPage7";
			this->tabPage7->UseVisualStyleBackColor = true;
			// 
			// label16
			// 
			this->label16->Location = System::Drawing::Point(69, 176);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(833, 72);
			this->label16->TabIndex = 18;
			this->label16->Text = resources->GetString(L"label16.Text");
			this->label16->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(715, 290);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(187, 106);
			this->button11->TabIndex = 17;
			this->button11->Text = L"Next Tip";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MainForm::button11_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(73, 290);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(185, 106);
			this->button10->TabIndex = 16;
			this->button10->Text = L"Previous Tip";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->button12);
			this->tabPage1->Controls->Add(this->btnOK);
			this->tabPage1->Location = System::Drawing::Point(4, 34);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(996, 807);
			this->tabPage1->TabIndex = 9;
			this->tabPage1->Text = L"tabPage8";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label17
			// 
			this->label17->Location = System::Drawing::Point(65, 82);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(894, 184);
			this->label17->TabIndex = 18;
			this->label17->Text = resources->GetString(L"label17.Text");
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(69, 293);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(192, 105);
			this->button12->TabIndex = 17;
			this->button12->Text = L"Previous Tip";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MainForm::button12_Click);
			// 
			// btnOK
			// 
			this->btnOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnOK->Location = System::Drawing::Point(399, 430);
			this->btnOK->Margin = System::Windows::Forms::Padding(5);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(186, 79);
			this->btnOK->TabIndex = 14;
			this->btnOK->Text = L"Start Training";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &MainForm::btnOK_Click);
			// 
			// tabTrials
			// 
			this->tabTrials->Controls->Add(this->trialArousalLevel);
			this->tabTrials->Controls->Add(this->trialValenceLevel);
			this->tabTrials->Controls->Add(this->trialIntensityLevel);
			this->tabTrials->Controls->Add(this->label9);
			this->tabTrials->Controls->Add(this->label8);
			this->tabTrials->Controls->Add(this->pictureBox4);
			this->tabTrials->Controls->Add(this->pictureBox3);
			this->tabTrials->Controls->Add(this->sliderIntensity);
			this->tabTrials->Controls->Add(this->sliderArousal);
			this->tabTrials->Controls->Add(this->button14);
			this->tabTrials->Controls->Add(this->trialProgress);
			this->tabTrials->Controls->Add(this->trialLabel);
			this->tabTrials->Controls->Add(this->nextTrial);
			this->tabTrials->Controls->Add(this->sliderValence);
			this->tabTrials->Controls->Add(this->pictureBox1);
			this->tabTrials->Location = System::Drawing::Point(4, 34);
			this->tabTrials->Name = L"tabTrials";
			this->tabTrials->Padding = System::Windows::Forms::Padding(3);
			this->tabTrials->Size = System::Drawing::Size(996, 807);
			this->tabTrials->TabIndex = 1;
			this->tabTrials->Text = L"Trials";
			this->tabTrials->UseVisualStyleBackColor = true;
			// 
			// trialArousalLevel
			// 
			this->trialArousalLevel->AutoSize = true;
			this->trialArousalLevel->Location = System::Drawing::Point(900, 536);
			this->trialArousalLevel->Name = L"trialArousalLevel";
			this->trialArousalLevel->Size = System::Drawing::Size(82, 25);
			this->trialArousalLevel->TabIndex = 16;
			this->trialArousalLevel->Text = L"label21";
			// 
			// trialValenceLevel
			// 
			this->trialValenceLevel->AutoSize = true;
			this->trialValenceLevel->Location = System::Drawing::Point(900, 357);
			this->trialValenceLevel->Name = L"trialValenceLevel";
			this->trialValenceLevel->Size = System::Drawing::Size(82, 25);
			this->trialValenceLevel->TabIndex = 15;
			this->trialValenceLevel->Text = L"label20";
			// 
			// trialIntensityLevel
			// 
			this->trialIntensityLevel->AutoSize = true;
			this->trialIntensityLevel->Location = System::Drawing::Point(895, 187);
			this->trialIntensityLevel->Name = L"trialIntensityLevel";
			this->trialIntensityLevel->Size = System::Drawing::Size(82, 25);
			this->trialIntensityLevel->TabIndex = 14;
			this->trialIntensityLevel->Text = L"label19";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(863, 236);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(133, 25);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Very intense";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(34, 236);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(174, 25);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Not Intense at all";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.InitialImage")));
			this->pictureBox4->Location = System::Drawing::Point(207, 178);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(662, 34);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox4->TabIndex = 11;
			this->pictureBox4->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.InitialImage")));
			this->pictureBox3->Location = System::Drawing::Point(207, 495);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(662, 141);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			// 
			// sliderIntensity
			// 
			this->sliderIntensity->Location = System::Drawing::Point(206, 218);
			this->sliderIntensity->Maximum = 100;
			this->sliderIntensity->Name = L"sliderIntensity";
			this->sliderIntensity->Size = System::Drawing::Size(663, 56);
			this->sliderIntensity->TabIndex = 9;
			this->sliderIntensity->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderIntensity_ValueChanged);
			// 
			// sliderArousal
			// 
			this->sliderArousal->Location = System::Drawing::Point(208, 642);
			this->sliderArousal->Maximum = 100;
			this->sliderArousal->Name = L"sliderArousal";
			this->sliderArousal->Size = System::Drawing::Size(663, 56);
			this->sliderArousal->TabIndex = 8;
			this->sliderArousal->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderArousal_ValueChanged);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(39, 340);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(118, 82);
			this->button14->TabIndex = 7;
			this->button14->Text = L"Continue";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MainForm::button14_Click);
			// 
			// trialProgress
			// 
			this->trialProgress->BackColor = System::Drawing::Color::Black;
			this->trialProgress->Location = System::Drawing::Point(207, 102);
			this->trialProgress->Name = L"trialProgress";
			this->trialProgress->Size = System::Drawing::Size(663, 22);
			this->trialProgress->TabIndex = 6;
			// 
			// trialLabel
			// 
			this->trialLabel->AutoSize = true;
			this->trialLabel->Location = System::Drawing::Point(204, 48);
			this->trialLabel->Name = L"trialLabel";
			this->trialLabel->Size = System::Drawing::Size(70, 25);
			this->trialLabel->TabIndex = 5;
			this->trialLabel->Text = L"label3";
			// 
			// nextTrial
			// 
			this->nextTrial->Location = System::Drawing::Point(766, 719);
			this->nextTrial->Name = L"nextTrial";
			this->nextTrial->Size = System::Drawing::Size(105, 54);
			this->nextTrial->TabIndex = 3;
			this->nextTrial->Text = L"Next";
			this->nextTrial->UseVisualStyleBackColor = true;
			this->nextTrial->Click += gcnew System::EventHandler(this, &MainForm::nextTrial_Click);
			// 
			// sliderValence
			// 
			this->sliderValence->Location = System::Drawing::Point(206, 428);
			this->sliderValence->Maximum = 100;
			this->sliderValence->Name = L"sliderValence";
			this->sliderValence->Size = System::Drawing::Size(663, 56);
			this->sliderValence->TabIndex = 2;
			this->sliderValence->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderValence_ValueChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(206, 280);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(663, 142);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// tabIntermediate
			// 
			this->tabIntermediate->Controls->Add(this->label18);
			this->tabIntermediate->Controls->Add(this->button6);
			this->tabIntermediate->Location = System::Drawing::Point(4, 34);
			this->tabIntermediate->Name = L"tabIntermediate";
			this->tabIntermediate->Padding = System::Windows::Forms::Padding(3);
			this->tabIntermediate->Size = System::Drawing::Size(996, 807);
			this->tabIntermediate->TabIndex = 7;
			this->tabIntermediate->Text = L"Intermediate";
			this->tabIntermediate->UseVisualStyleBackColor = true;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(129, 151);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(756, 225);
			this->label18->TabIndex = 18;
			this->label18->Text = resources->GetString(L"label18.Text");
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(383, 409);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(191, 119);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Start Testing";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
			// 
			// tabTests
			// 
			this->tabTests->Controls->Add(this->testArousalLevel);
			this->tabTests->Controls->Add(this->testValenceLevel);
			this->tabTests->Controls->Add(this->testIntensityLevel);
			this->tabTests->Controls->Add(this->label11);
			this->tabTests->Controls->Add(this->label10);
			this->tabTests->Controls->Add(this->pictureBox6);
			this->tabTests->Controls->Add(this->pictureBox2);
			this->tabTests->Controls->Add(this->pictureBox5);
			this->tabTests->Controls->Add(this->sliderIntensityTest);
			this->tabTests->Controls->Add(this->sliderArousalTest);
			this->tabTests->Controls->Add(this->button15);
			this->tabTests->Controls->Add(this->testProgress);
			this->tabTests->Controls->Add(this->nextTest);
			this->tabTests->Controls->Add(this->sliderValenceTest);
			this->tabTests->Controls->Add(this->testLabel);
			this->tabTests->Location = System::Drawing::Point(4, 34);
			this->tabTests->Name = L"tabTests";
			this->tabTests->Size = System::Drawing::Size(996, 807);
			this->tabTests->TabIndex = 8;
			this->tabTests->Text = L"Test";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(860, 203);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(133, 25);
			this->label11->TabIndex = 19;
			this->label11->Text = L"Very intense";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(36, 203);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(174, 25);
			this->label10->TabIndex = 18;
			this->label10->Text = L"Not Intense at all";
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.InitialImage")));
			this->pictureBox6->Location = System::Drawing::Point(207, 489);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(662, 141);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox6->TabIndex = 17;
			this->pictureBox6->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.InitialImage")));
			this->pictureBox2->Location = System::Drawing::Point(206, 263);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(663, 142);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox2->TabIndex = 16;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.InitialImage")));
			this->pictureBox5->Location = System::Drawing::Point(206, 151);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(662, 34);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox5->TabIndex = 15;
			this->pictureBox5->TabStop = false;
			// 
			// sliderIntensityTest
			// 
			this->sliderIntensityTest->Location = System::Drawing::Point(206, 191);
			this->sliderIntensityTest->Maximum = 100;
			this->sliderIntensityTest->Name = L"sliderIntensityTest";
			this->sliderIntensityTest->Size = System::Drawing::Size(662, 56);
			this->sliderIntensityTest->TabIndex = 14;
			this->sliderIntensityTest->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderIntensityTest_ValueChanged);
			// 
			// sliderArousalTest
			// 
			this->sliderArousalTest->Location = System::Drawing::Point(206, 636);
			this->sliderArousalTest->Maximum = 100;
			this->sliderArousalTest->Name = L"sliderArousalTest";
			this->sliderArousalTest->Size = System::Drawing::Size(663, 56);
			this->sliderArousalTest->TabIndex = 13;
			this->sliderArousalTest->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderArousalTest_ValueChanged);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(41, 354);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(114, 68);
			this->button15->TabIndex = 12;
			this->button15->Text = L"Continue";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MainForm::button15_Click);
			// 
			// testProgress
			// 
			this->testProgress->BackColor = System::Drawing::Color::Black;
			this->testProgress->Location = System::Drawing::Point(206, 90);
			this->testProgress->Name = L"testProgress";
			this->testProgress->Size = System::Drawing::Size(662, 22);
			this->testProgress->TabIndex = 11;
			// 
			// nextTest
			// 
			this->nextTest->Location = System::Drawing::Point(764, 696);
			this->nextTest->Name = L"nextTest";
			this->nextTest->Size = System::Drawing::Size(105, 54);
			this->nextTest->TabIndex = 10;
			this->nextTest->Text = L"Next";
			this->nextTest->UseVisualStyleBackColor = true;
			this->nextTest->Click += gcnew System::EventHandler(this, &MainForm::nextTest_Click);
			// 
			// sliderValenceTest
			// 
			this->sliderValenceTest->Location = System::Drawing::Point(206, 411);
			this->sliderValenceTest->Maximum = 100;
			this->sliderValenceTest->Name = L"sliderValenceTest";
			this->sliderValenceTest->Size = System::Drawing::Size(663, 56);
			this->sliderValenceTest->TabIndex = 9;
			this->sliderValenceTest->ValueChanged += gcnew System::EventHandler(this, &MainForm::sliderValenceTest_ValueChanged);
			// 
			// testLabel
			// 
			this->testLabel->AutoSize = true;
			this->testLabel->Location = System::Drawing::Point(202, 45);
			this->testLabel->Name = L"testLabel";
			this->testLabel->Size = System::Drawing::Size(117, 25);
			this->testLabel->TabIndex = 6;
			this->testLabel->Text = L"label3_test";
			// 
			// TabGoQuest
			// 
			this->TabGoQuest->Controls->Add(this->label3);
			this->TabGoQuest->Controls->Add(this->button13);
			this->TabGoQuest->Location = System::Drawing::Point(4, 34);
			this->TabGoQuest->Name = L"TabGoQuest";
			this->TabGoQuest->Padding = System::Windows::Forms::Padding(3);
			this->TabGoQuest->Size = System::Drawing::Size(996, 807);
			this->TabGoQuest->TabIndex = 10;
			this->TabGoQuest->Text = L"Questionnaire";
			this->TabGoQuest->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(67, 222);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(906, 124);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Congratulations! You have now completed all of the tests. We have a few questions"
				L" for you to answer.";
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(381, 405);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(165, 76);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Confirm";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MainForm::button13_Click);
			// 
			// tabQuest
			// 
			this->tabQuest->Controls->Add(this->radioButton8);
			this->tabQuest->Controls->Add(this->radioButton7);
			this->tabQuest->Controls->Add(this->radioButton6);
			this->tabQuest->Controls->Add(this->Q2Text);
			this->tabQuest->Controls->Add(this->label5);
			this->tabQuest->Controls->Add(this->label4);
			this->tabQuest->Controls->Add(this->button17);
			this->tabQuest->Location = System::Drawing::Point(4, 34);
			this->tabQuest->Name = L"tabQuest";
			this->tabQuest->Padding = System::Windows::Forms::Padding(3);
			this->tabQuest->Size = System::Drawing::Size(996, 807);
			this->tabQuest->TabIndex = 12;
			this->tabQuest->Text = L"Ask";
			this->tabQuest->UseVisualStyleBackColor = true;
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(608, 152);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(157, 29);
			this->radioButton8->TabIndex = 7;
			this->radioButton8->TabStop = true;
			this->radioButton8->Text = L"Both-handed";
			this->radioButton8->UseVisualStyleBackColor = true;
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Location = System::Drawing::Point(371, 152);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(162, 29);
			this->radioButton7->TabIndex = 6;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Right-handed";
			this->radioButton7->UseVisualStyleBackColor = true;
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(126, 152);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(149, 29);
			this->radioButton6->TabIndex = 5;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Left-handed";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// Q2Text
			// 
			this->Q2Text->Location = System::Drawing::Point(85, 438);
			this->Q2Text->Name = L"Q2Text";
			this->Q2Text->Size = System::Drawing::Size(771, 138);
			this->Q2Text->TabIndex = 4;
			this->Q2Text->Text = L"";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(81, 251);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(867, 136);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Question 2: Are you involved in activities that require intensive use of hands \?\r"
				L"\n\r\nIf yes, please specify what activities \? (e.g., rock climbing)\r\n\r\nIf No, plea"
				L"se enter \'No\'";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(80, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(867, 136);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Question 1: Are you right or left-handed \?";
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(394, 685);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(172, 72);
			this->button17->TabIndex = 0;
			this->button17->Text = L"Confirm";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MainForm::button17_Click);
			// 
			// tabQuest1
			// 
			this->tabQuest1->Controls->Add(this->radioButton5);
			this->tabQuest1->Controls->Add(this->radioButton4);
			this->tabQuest1->Controls->Add(this->radioButton3);
			this->tabQuest1->Controls->Add(this->radioButton2);
			this->tabQuest1->Controls->Add(this->radioButton1);
			this->tabQuest1->Controls->Add(this->button18);
			this->tabQuest1->Controls->Add(this->label7);
			this->tabQuest1->Controls->Add(this->Q3Text);
			this->tabQuest1->Controls->Add(this->label6);
			this->tabQuest1->Location = System::Drawing::Point(4, 34);
			this->tabQuest1->Name = L"tabQuest1";
			this->tabQuest1->Padding = System::Windows::Forms::Padding(3);
			this->tabQuest1->Size = System::Drawing::Size(996, 807);
			this->tabQuest1->TabIndex = 13;
			this->tabQuest1->Text = L"Ask1";
			this->tabQuest1->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(76, 389);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(205, 29);
			this->radioButton5->TabIndex = 11;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Never tried before";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(76, 529);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(147, 29);
			this->radioButton4->TabIndex = 10;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Know it well";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(76, 494);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(177, 29);
			this->radioButton3->TabIndex = 9;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Use it regularly";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(76, 459);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(197, 29);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Tried a few times";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(76, 424);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(153, 29);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Tried it once";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(411, 671);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(161, 85);
			this->button18->TabIndex = 6;
			this->button18->Text = L"Confirm";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MainForm::button18_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(57, 278);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(754, 75);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Question 4: Have you had used a mid - air haptic device before \?\r\n\r\nIf yes, how e"
				L"xperienced are you with mid - air haptics \? You can choose from:";
			// 
			// Q3Text
			// 
			this->Q3Text->Location = System::Drawing::Point(57, 120);
			this->Q3Text->Name = L"Q3Text";
			this->Q3Text->Size = System::Drawing::Size(880, 112);
			this->Q3Text->TabIndex = 3;
			this->Q3Text->Text = L"";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(53, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(893, 136);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Question 3: In 3 words, how would you describe the experience of the mid-air hapt"
				L"ic sensation on your palm \?";
			// 
			// endPage
			// 
			this->endPage->Controls->Add(this->goodbyLabel);
			this->endPage->Location = System::Drawing::Point(4, 34);
			this->endPage->Name = L"endPage";
			this->endPage->Padding = System::Windows::Forms::Padding(3);
			this->endPage->Size = System::Drawing::Size(996, 807);
			this->endPage->TabIndex = 11;
			this->endPage->Text = L"EndPage";
			this->endPage->UseVisualStyleBackColor = true;
			// 
			// goodbyLabel
			// 
			this->goodbyLabel->AutoSize = true;
			this->goodbyLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->goodbyLabel->Location = System::Drawing::Point(71, 348);
			this->goodbyLabel->Name = L"goodbyLabel";
			this->goodbyLabel->Size = System::Drawing::Size(864, 51);
			this->goodbyLabel->TabIndex = 0;
			this->goodbyLabel->Text = L"Thank you very much for the participation!";
			// 
			// trialTimer
			// 
			this->trialTimer->Interval = 1000;
			this->trialTimer->Tick += gcnew System::EventHandler(this, &MainForm::trialTimer_Tick);
			// 
			// testTimer
			// 
			this->testTimer->Interval = 1000;
			this->testTimer->Tick += gcnew System::EventHandler(this, &MainForm::testTimer_Tick);
			// 
			// testIntensityLevel
			// 
			this->testIntensityLevel->AutoSize = true;
			this->testIntensityLevel->Location = System::Drawing::Point(888, 160);
			this->testIntensityLevel->Name = L"testIntensityLevel";
			this->testIntensityLevel->Size = System::Drawing::Size(82, 25);
			this->testIntensityLevel->TabIndex = 20;
			this->testIntensityLevel->Text = L"label19";
			// 
			// testValenceLevel
			// 
			this->testValenceLevel->AutoSize = true;
			this->testValenceLevel->Location = System::Drawing::Point(888, 380);
			this->testValenceLevel->Name = L"testValenceLevel";
			this->testValenceLevel->Size = System::Drawing::Size(82, 25);
			this->testValenceLevel->TabIndex = 21;
			this->testValenceLevel->Text = L"label19";
			// 
			// testArousalLevel
			// 
			this->testArousalLevel->AutoSize = true;
			this->testArousalLevel->Location = System::Drawing::Point(888, 605);
			this->testArousalLevel->Name = L"testArousalLevel";
			this->testArousalLevel->Size = System::Drawing::Size(82, 25);
			this->testArousalLevel->TabIndex = 22;
			this->testArousalLevel->Text = L"label19";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(13, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 845);
			this->Controls->Add(this->stepsControl);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->stepsControl->ResumeLayout(false);
			this->tabID->ResumeLayout(false);
			this->tabID->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage4->ResumeLayout(false);
			this->tabPage5->ResumeLayout(false);
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->tabPage7->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabTrials->ResumeLayout(false);
			this->tabTrials->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderIntensity))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderArousal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderValence))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->tabIntermediate->ResumeLayout(false);
			this->tabIntermediate->PerformLayout();
			this->tabTests->ResumeLayout(false);
			this->tabTests->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderIntensityTest))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderArousalTest))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderValenceTest))->EndInit();
			this->TabGoQuest->ResumeLayout(false);
			this->tabQuest->ResumeLayout(false);
			this->tabQuest->PerformLayout();
			this->tabQuest1->ResumeLayout(false);
			this->tabQuest1->PerformLayout();
			this->endPage->ResumeLayout(false);
			this->endPage->PerformLayout();
			this->ResumeLayout(false);

		};

#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->stepsControl->ItemSize = System::Drawing::Size(0, 1);
		this->stepsControl->SizeMode = TabSizeMode::Fixed;
		this->lbWelcome->Text = "";

		_trialWidth = trialProgress->Width;
		trialProgress->Width = 0;

		_testWidth = testProgress->Width;
		testProgress->Width = 0;
		
		
		System::Threading::TimerCallback^ testCallback = gcnew System::Threading::TimerCallback(this, &MainForm::OnTestStimulusTimer);
		System::Threading::TimerCallback^ trialCallback = gcnew System::Threading::TimerCallback(this, &MainForm::OnTrialStimulusTimer);

		_testTimer = gcnew System::Threading::Timer(testCallback);
		_trialTimer = gcnew System::Threading::Timer(trialCallback);


		PBDEngine_CWrapper_Initialize();
		//PBDEngine_CWrapper_RegisterPrintFuncs(print, print, print);
		PBDEngine_CWrapper_SetupEngine(2000000, PBDEngine::GSPAT_SOLVER::V2);
		pm = PBDEngine_CWrapper_StartEngine(4, 32, 0, 38, false);
		PBDEngine_CWrapper_SetupPhaseOnly(true);

	};

	System::Threading::Timer^ _testTimer;
	System::Threading::Timer^ _trialTimer;

	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ participant_id = this->participantID->Text;
		//this->lbWelcome->Text = "Hello Participant: " + participant_id;


		//// Read the modulation parameters for this user and this test(valence or intensity) to vector
		std::ifstream is_prior("C:\\Users\\User\\Desktop\\User-study-1\\user_studies_1-pilot-study\\priors\\parameters_prior" + msclr::interop::marshal_as<std::string>(participant_id) + ".txt");
		int bf_prior, pts_prior, spd_prior, frq_prior, shp_prior;
		while (is_prior >> bf_prior >> pts_prior >> spd_prior >> frq_prior >> shp_prior)
		{
			speed_tests.push_back({ bf_prior,pts_prior,spd_prior,frq_prior,shp_prior });
		}

		int speed_tests_size = speed_tests.size();


		std::ifstream is("C:\\Users\\User\\Desktop\\User-study-1\\user_studies_1-pilot-study\\tests\\parameters_test" + msclr::interop::marshal_as<std::string>(participant_id) + ".txt");

		int bf, pts, spd, frq, shp;
		while (is >> bf >> pts >> spd >> frq >> shp)
		{
			freq_tests.push_back({ bf,pts,spd,frq,shp });
		}

		int freq_tests_size = freq_tests.size();

		// Padding ID into '0'+string(ID) format 
		std::string ID_str = msclr::interop::marshal_as<std::string>(participant_id->PadLeft(2, '0'));

		responses.open("C:\\Users\\User\\Desktop\\User-study-1\\user_studies_1-pilot-study\\responses\\responses-" + ID_str + ".csv");
		quest_responses.open("C:\\Users\\User\\Desktop\\User-study-1\\user_studies_1-pilot-study\\responses\\responses-" + ID_str + ".txt");
		q_responses.open("C:\\Users\\User\\Desktop\\User-study-1\\user_studies_1-pilot-study\\responses\\quest-responses-" + ID_str + ".csv");
		responses << "ID" << "," << "Base frequency" << "," << "NumPoints" << "," << "Drawing speed" << "," << "Drawing frequency" << "," << "Shape" << "," << "Intensity level" << "," << "Valence level" << "," << "Arousal level" << "\n";
		q_responses << "ID" << "," << "Dominant hand" << "," << "Intensive hand" << "," << "Experienced" << "\n";
		declareContent(pm, side1);
		configureContent(pm, shapes[curShape], curNumPoints, curFrequencyBase, curNumSamples);


		NextStep();
	};
	// goto next tab
	private: System::Void NextStep() {
		if (this->stepsControl->SelectedIndex + 1 < this->stepsControl->TabPages->Count)
			this->stepsControl->SelectedIndex++;
	};
	// goto previous tab
	private: System::Void PreviousStep() {
		if (this->stepsControl->SelectedIndex > 0)
			this->stepsControl->SelectedIndex--;
	}; 
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		PBDEngine_CWrapper_StopEngine();
		PBDEngine_CWrapper_Release();
	};
	// control the action to perform when specific tab is reached 
	private: System::Void stepsControl_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		if (stepsControl->SelectedTab == tabTrials) 
		{
			speed_test_Index = -1;
			nextTrial_Click(sender, e);
		}
		if (stepsControl->SelectedTab == tabTests) {
			freq_test_Index = -1;
			nextTest_Click(sender, e);
		}
		if (stepsControl->SelectedTab == endPage) {
			responses.close();
			quest_responses.close();
			Application::Exit();
		}
	};

	private: System::Void IDConfirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ participant_id = this->participantID->Text;
		if (msclr::interop::marshal_as<std::string>(participant_id) == "") {
			this->lbWelcome->Text = "Please provide participant ID";
		}
		else {
			this->lbWelcome->Text = "Hello Participant: " + participant_id;
			NextStep();
		}
	};
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) { PreviousStep(); };
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) { PreviousStep(); };
	private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) { NextStep(); };
	private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e) { PreviousStep(); };
	private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) { 
		NextStep(); 
	};
	// This will allow user to go next trial
	private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
		if (trialPass == false) {
			trialPass = true;
		}
	}
	// This will allow user to go next test
	private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
		if (testPass == false) {
			testPass = true;
		}
	}
	private: System::Void button17_Click(System::Object^ sender, System::EventArgs^ e) {

		if ((radioButton6->Checked == false && radioButton7->Checked == false && radioButton8->Checked == false ) || msclr::interop::marshal_as<std::string>(Q2Text->Text) == "") {

		}
		else {
			std::string Q1text;
			int Q1Option;
			if (radioButton6->Checked) {
				Q1text = msclr::interop::marshal_as<std::string>(radioButton6->Text);
				Q1Option = 1;
			}
			if (radioButton7->Checked) {
				Q1text = msclr::interop::marshal_as<std::string>(radioButton7->Text);
				Q1Option = 2;
			}
			if (radioButton8->Checked) {
				Q1text = msclr::interop::marshal_as<std::string>(radioButton8->Text);
				Q1Option = 3;
			}

			std::string Q2text;
			int Q2Option;


			if (msclr::interop::marshal_as<std::string>(Q2Text->Text) == "No" || msclr::interop::marshal_as<std::string>(Q2Text->Text) == "no") {
				Q2text = "No";
				Q2Option = 0;
			}
			else {
				Q2text = msclr::interop::marshal_as<std::string>(Q2Text->Text);
				Q2Option = 1;
			}

			q_responses << msclr::interop::marshal_as<std::string>(this->participantID->Text) << "," << Q1Option << "," << Q2Option << "," << std::flush;
			quest_responses << "Question 1: Are you right or left-handed ? You can input 1) left-handed, 2) right-handed, 3) both-handed:\n\n"
				<< "answer: " + Q1text << "\n\n"
				<< "Question 2: Are you involved in activities that require intensive use of hands ?.\n\nIf yes, please specify what activities ? (e.g., rock climbing)\n\nIf No, please enter no.\n\n"
				<< "answer: " + Q2text << "\n\n" << std::flush;

			NextStep();
		}
	};

	//private: System::Void button16_Click(System::Object^ sender, System::EventArgs^ e) {
	//	responses.close();
	//	quest_responses.close();
	//	Application::Exit();
	//};

	private: System::Void button18_Click(System::Object^ sender, System::EventArgs^ e) {

		if ((radioButton5->Checked == false && radioButton1->Checked == false && radioButton2->Checked == false && radioButton3->Checked == false && radioButton4->Checked == false) || msclr::interop::marshal_as<std::string>(Q3Text->Text) == "") {

		}
		else {
			std::string Q4text;
			int Q4Option;
			if (radioButton5->Checked) {
				Q4text = msclr::interop::marshal_as<std::string>(radioButton5->Text);
				Q4Option = 0;
			}
			if (radioButton1->Checked) {
				Q4text = msclr::interop::marshal_as<std::string>(radioButton1->Text);
				Q4Option = 1;
			}
			if (radioButton2->Checked) {
				Q4text = msclr::interop::marshal_as<std::string>(radioButton2->Text);
				Q4Option = 2;
			}
			if (radioButton3->Checked) {
				Q4text = msclr::interop::marshal_as<std::string>(radioButton3->Text);
				Q4Option = 3;
			}
			if (radioButton4->Checked) {
				Q4text = msclr::interop::marshal_as<std::string>(radioButton4->Text);
				Q4Option = 4;
			}
			q_responses << Q4Option << "\n" << std::flush;
			quest_responses << "Question 3: In 3 words, how would you describe the experience of the mid-air haptic sensation on your palm?"
				<< "answer: " + msclr::interop::marshal_as<std::string>(Q3Text->Text) << "\n\n"
				<< "Question 4: Have you had used a mid-air haptic device before ? (Yes/No).\n\nIf yes, how experienced are you with mid-air haptics ? You can choose from: ?\n\n1) tried it once\n2) tried a few times\n3) use it regularly\n4) know it well\n\nIf No, please enter no.\n\n"
				<< "answer: " + Q4text << "\n\n" << std::endl;
			NextStep();
		}
		
	}
	bool selfUpdateNotHumanUpdate = false;
	// determine if intensity is changed for trials
	bool intensity_changed = false;
	private: System::Void sliderIntensity_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			trialIntensityLevel->Text = ((sliderIntensity->Value) / 10.0f).ToString();
			if (valence_changed == true && arousal_changed == true) {
				nextTrial->Show();
				if (trialPass == false) {
					button14->Show();
				}
			}
			intensity_changed = true;
		}
		else { selfUpdateNotHumanUpdate = false; }

	}
	// determine if valence is changed for trials
	bool valence_changed = false;
	private: System::Void sliderValence_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			trialValenceLevel->Text = ((sliderValence->Value) / 10.0f).ToString();
			if (intensity_changed == true && arousal_changed == true) {
				nextTrial->Show();
				if (trialPass == false) {
					button14->Show();
				}
			}
			valence_changed = true;
		}else{ selfUpdateNotHumanUpdate = false; }
		
	}
	// determine if arousal is changed for trials
	bool arousal_changed = false;
	private: System::Void sliderArousal_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			trialArousalLevel->Text = ((sliderArousal->Value) / 10.0f).ToString();
			if (intensity_changed == true && valence_changed == true) {
				nextTrial->Show();
				if (trialPass == false) {
					button14->Show();
				}
			}
			arousal_changed = true;
		}else{ selfUpdateNotHumanUpdate = false; }
		
	}

	// determine if intensity is changed for tests
	bool intensityTest_changed = false;
	private: System::Void sliderIntensityTest_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			testIntensityLevel->Text = ((sliderIntensityTest->Value) / 10.0f).ToString();
			if (valenceTest_changed == true && arousalTest_changed == true) {
				nextTest->Show();
				if (testPass == false) {
					button15->Show();
				}
			}
			intensityTest_changed = true;
		}else{ selfUpdateNotHumanUpdate = false; }

	}
	// determine if valence is changed for tests
	bool valenceTest_changed = false;
	private: System::Void sliderValenceTest_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			testValenceLevel->Text = ((sliderValenceTest->Value) / 10.0f).ToString();
			if (intensityTest_changed == true && arousalTest_changed == true) {
				nextTest->Show();
				if (testPass == false) {
					button15->Show();
				}
			}
			valenceTest_changed = true;
		}
		else { selfUpdateNotHumanUpdate = false; }
	}
	// determine if arousal is changed for tests
	bool arousalTest_changed = false;
	private: System::Void sliderArousalTest_ValueChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (selfUpdateNotHumanUpdate == false) {
			testArousalLevel->Text = ((sliderArousalTest->Value) / 10.0f).ToString();
			if (intensityTest_changed == true && valenceTest_changed == true) {
				nextTest->Show();
				if (testPass == false) {
					button15->Show();
				}
			}
			arousalTest_changed = true;
		}
		else { selfUpdateNotHumanUpdate = false; }

	}
	// This is for the trials
	bool trialPass = true;
	private: System::Void nextTrial_Click(System::Object^ sender, System::EventArgs^ e) {		
	
		if (trialPass == true) {
			
			nextTrial->Hide();
			button14->Hide();
			if (speed_test_Index >= 0)
			{
				// save values
				double intensity_level = sliderIntensity->Value / 10.0f;// sliderIntensity->Value;
				double valence_level = sliderValence->Value / 10.0f;
				double arousal_level = sliderArousal->Value / 10.0f;// sliderArousal->Value;
					//responses << msclr::interop::marshal_as<std::string>(this->participantID->Text) << "," << curFrequencyBase << "," << curNumPoints << "," << speed_tests[speed_test_Index][2] << "," << speed_tests[speed_test_Index][3] << "," << speed_tests[speed_test_Index][4] << "," << intensity_level << "," << valence_level << "," << arousal_level << "\n" << std::flush;
			}
			// This is to set bar positions to the places we want before user scrolls, the value change action brought by this will not be considered as human input
			/////////////////////////////////////////////////////////////////////////////////////////
			selfUpdateNotHumanUpdate = true;
			sliderIntensity->Value = sliderIntensity->Minimum;
			trialIntensityLevel->Text = ((sliderIntensity->Value) / 10.0f).ToString();
			selfUpdateNotHumanUpdate = true;
			sliderValence->Value = (sliderValence->Maximum + sliderValence->Minimum) / 2.0;
			trialValenceLevel->Text = ((sliderValence->Value) / 10.0f).ToString();
			selfUpdateNotHumanUpdate = true;
			sliderArousal->Value = sliderArousal->Minimum;
			trialArousalLevel->Text = ((sliderArousal->Value) / 10.0f).ToString();
			/////////////////////////////////////////////////////////////////////////////////////////

			speed_test_Index++;
			if (speed_test_Index < speed_tests.size())
			{
				this->trialLabel->Text = System::String::Format("Stimulation Trial {0} please focus on how you perceive the stimulus regarding its intensity, pleasantness, and emotional activation.", speed_test_Index + 1);
				curFrequencyBase = speed_tests[speed_test_Index][0];
				curNumPoints = speed_tests[speed_test_Index][1];
				curShape = speed_tests[speed_test_Index][4];

				debugprintf("\n trialcase %d's base frequency is %dHz, number of focal points is %d ", speed_test_Index + 1, speed_tests[speed_test_Index][0], speed_tests[speed_test_Index][1]);
				//if it is circle
				if (curShape == 0) {
					side1 = 0.063663854846411f;
					declareContent(pm, side1);
					configureContent(pm, shapes[curShape], curNumPoints, curFrequencyBase, curNumSamples);
				}

				//if it is triangle
				if (curShape == 1) {
					side1 = 0.0666667f;
					declareContent(pm, side1);
					configureContent(pm, shapes[curShape], curNumPoints, curFrequencyBase, curNumSamples);
				}

				sliderArousal->Enabled = false;
				sliderValence->Enabled = false;
				sliderIntensity->Enabled = false;
				nextTrial->Enabled = false;
				trialStarted = System::DateTime::Now;
				trialProgress->Width = (trialTimer->Interval / (stimulusSeconds * 1000.0)) * _trialWidth;
				PBDEngine_CWrapper_commitUpdates(pm);
				_trialTimer->Change(stimulusSeconds * 1000, -1);
				trialTimer->Enabled = true;
				
			}
			// if stimuli are all executed 
			else { NextStep(); }

			// if stimulus reaches 21, rest
			if (speed_test_Index == 20) {
				trialPass = false;
			}
			
		}
	}
	// Stop rendering for trial and reset trial conditions
	private: System::DateTime trialStarted;
	private: System::Void OnTrialStimulusTimer(System::Object^ state) {
		configureContent(pm, shapes[curShape], 0, curFrequencyBase, curNumSamples); // stop haptic
		PBDEngine_CWrapper_commitUpdates(pm);

		System::Action^ action = gcnew System::Action(this, &MainForm::ResetTrial);
		BeginInvoke(action);
	};
	private: System::Void ResetTrial()
	{
		trialTimer->Enabled = false;
		trialStarted = System::DateTime::Now;
		trialProgress->Width = 0;
		nextTrial->Enabled = true;
		sliderValence->Enabled = true;
		sliderArousal->Enabled = true;
		sliderIntensity->Enabled = true;
		valence_changed = false;
		arousal_changed = false;
		intensity_changed = false;
		selfUpdateNotHumanUpdate = false;
	};
	private: System::Void trialTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		auto elapsedms = (System::DateTime::Now - trialStarted).TotalMilliseconds + trialTimer->Interval;
		trialProgress->Width = System::Math::Min(elapsedms / (stimulusSeconds * 1000.0), 1.0) * _trialWidth;
	}

	// This is for the tests
	bool testPass = true;
	private: System::Void nextTest_Click(System::Object^ sender, System::EventArgs^ e) {

		if (testPass == true) {
			nextTest->Hide();
			button15->Hide();
			
			if (freq_test_Index >= 0)
			{
				// save values
				double intensity_level = sliderIntensityTest->Value / 10.0f;;// sliderIntensity->Value;
				double valence_level = sliderValenceTest->Value / 10.0f;
				double arousal_level = sliderArousalTest->Value / 10.0f;;// sliderArousal->Value;

				responses << msclr::interop::marshal_as<std::string>(this->participantID->Text) << "," << curFrequencyBase << "," << curNumPoints << "," << freq_tests[freq_test_Index][2] << "," << freq_tests[freq_test_Index][3] << "," << freq_tests[freq_test_Index][4] << "," << intensity_level << "," << valence_level << "," << arousal_level << "\n" << std::flush;
			}
			// This is to set bar positions to the places we want before user scrolls
			/////////////////////////////////////////////////////////////////////////////////////////
			selfUpdateNotHumanUpdate = true;
			sliderIntensityTest->Value = sliderIntensityTest->Minimum;
			testIntensityLevel->Text = ((sliderIntensityTest->Value) / 10.0f).ToString();
			selfUpdateNotHumanUpdate = true;
			sliderValenceTest->Value = (sliderValenceTest->Maximum + sliderValenceTest->Minimum) / 2.0;
			testValenceLevel->Text = ((sliderValenceTest->Value) / 10.0f).ToString();
			selfUpdateNotHumanUpdate = true;
			sliderArousalTest->Value = sliderArousalTest->Minimum;
			testArousalLevel->Text = ((sliderArousalTest->Value) / 10.0f).ToString();
			/////////////////////////////////////////////////////////////////////////////////////////

			freq_test_Index++;
			if (freq_test_Index < freq_tests.size())
			{
				this->testLabel->Text = System::String::Format("Stimulation Test {0} please focus on how you perceive the stimulus regarding its intensity, pleasantness, and emotional activation.", freq_test_Index + 1);
				curFrequencyBase = freq_tests[freq_test_Index][0];
				curNumPoints = freq_tests[freq_test_Index][1];
				curShape = freq_tests[freq_test_Index][4];

				debugprintf("\n testcase %d's base frequency is %dHz, number of focal points is %d ", freq_test_Index + 1, freq_tests[freq_test_Index][0], freq_tests[freq_test_Index][1]);
				//if it is circle
				if (curShape == 0) {
					side1 = 0.063663854846411f;
					declareContent(pm, side1);
					configureContent(pm, shapes[curShape], curNumPoints, curFrequencyBase, curNumSamples);
				}

				//if it is triangle
				if (curShape == 1) {
					side1 = 0.0666667f;
					declareContent(pm, side1);
					configureContent(pm, shapes[curShape], curNumPoints, curFrequencyBase, curNumSamples);
				}
				sliderArousalTest->Enabled = false;
				sliderValenceTest->Enabled = false;
				sliderIntensityTest->Enabled = false;
				nextTest->Enabled = false;
				testStarted = System::DateTime::Now;
				testProgress->Width = (testTimer->Interval / (stimulusSeconds * 1000.0)) * _testWidth;
				PBDEngine_CWrapper_commitUpdates(pm);
				_testTimer->Change(stimulusSeconds * 1000, -1);
				testTimer->Enabled = true;
				selfUpdateNotHumanUpdate = false;
			}
			else
			{
				NextStep();
			}
		}
		if (freq_test_Index == 10) {
			testPass = false;
		}
	};
	private: System::DateTime testStarted;
	private: System::Void OnTestStimulusTimer(System::Object^ state) {
			configureContent(pm, shapes[curShape], 0, curFrequencyBase, curNumSamples); // stop haptic
			PBDEngine_CWrapper_commitUpdates(pm);

			System::Action^ action = gcnew System::Action(this, &MainForm::ResetTest);
			BeginInvoke(action);
	};
	private: System::Void ResetTest()
	{
		testTimer->Enabled = false;
		testStarted = System::DateTime::Now;
		testProgress->Width = 0;
		nextTest->Enabled = true;
		sliderValenceTest->Enabled = true;
		sliderArousalTest->Enabled = true;
		sliderIntensityTest->Enabled = true;
		valenceTest_changed = false;
		arousalTest_changed = false;
		intensityTest_changed = false;
	};
	private: System::Void testTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		auto elapsedms = (System::DateTime::Now - testStarted).TotalMilliseconds + testTimer->Interval;
		testProgress->Width = System::Math::Min(elapsedms / (stimulusSeconds * 1000.0), 1.0) * _testWidth;
	}
};
}





// Functions for PBD engine
void declareContent(PBD_PrimitiveManager_Handler pm, float side) {
	//Let's delete the shapes if they had already been created:
	for (int s = 0; s < 5; s++)
		if (shapes[s] != NULL) {
			delete shapes[s];
			shapes[s] = NULL;
		}

	//A. Fixed amplitude (used with PoV circles)
	float a1_data[] = { 15000.0f };
	fixedAmplitude = PBDEngine_CWrapper_createAmplitudesDescriptor(pm, a1_data, 1);

	//B. Declare shapes (this is a declaration... we will need to sample them at specific frequencies later, diameter). 	
	// zhouyang : the side here is single half of the path that finish stimulation (just for the line)
	{
		std::vector<glm::vec4> posCircle;//Approximated as a poligon with 32 sides
		for (int i = 0; i < 32; i++)
			posCircle.push_back(glm::vec4(side / 2 * cosf(2 * M_PI * i / 32.0f), side / 2 * sinf(2 * M_PI * i / 32.0f), 0.11f, 1));
		shapes[0] = new  HapticShape("Circle", posCircle);

		std::vector<glm::vec4> posTriangle;
		posTriangle.push_back(glm::vec4(-(side / 2) * tanf(M_PI / 6), -side / 2, 0.11f, 1));
		posTriangle.push_back(glm::vec4(-(side / 2) * tanf(M_PI / 6), side / 2, 0.11f, 1));
		posTriangle.push_back(glm::vec4((side)*sinf(M_PI / 3) - (side / 2) * tanf(M_PI / 6), 0, 0.11f, 1));
		shapes[1] = new  HapticShape("Triangle", posTriangle);

		std::vector<glm::vec4> posSquare;
		posSquare.push_back(glm::vec4(-side / 2, -side / 2, 0.11f, 1));
		posSquare.push_back(glm::vec4(side / 2, -side / 2, 0.11f, 1));
		posSquare.push_back(glm::vec4(side / 2, side / 2, 0.11f, 1));
		posSquare.push_back(glm::vec4(-side / 2, side / 2, 0.11f, 1));
		shapes[2] = new HapticShape("Square", posSquare);

		std::vector<glm::vec4> posStar;
		posStar.push_back(glm::vec4(side / 2 * cosf(0 * 2 * M_PI / 5.0f), side / 2 * sinf(0 * 2 * M_PI / 5.0f), 0.11f, 1));
		posStar.push_back(glm::vec4(side / 2 * cosf(2 * 2 * M_PI / 5.0f), side / 2 * sinf(2 * 2 * M_PI / 5.0f), 0.11f, 1));
		posStar.push_back(glm::vec4(side / 2 * cosf(4 * 2 * M_PI / 5.0f), side / 2 * sinf(4 * 2 * M_PI / 5.0f), 0.11f, 1));
		posStar.push_back(glm::vec4(side / 2 * cosf(1 * 2 * M_PI / 5.0f), side / 2 * sinf(1 * 2 * M_PI / 5.0f), 0.11f, 1));
		posStar.push_back(glm::vec4(side / 2 * cosf(3 * 2 * M_PI / 5.0f), side / 2 * sinf(3 * 2 * M_PI / 5.0f), 0.11f, 1));
		shapes[3] = new HapticShape("Star", posStar);

		std::vector<glm::vec4> posLine;
		posLine.push_back(glm::vec4(-side / 2, 0, 0.11f, 1));
		posLine.push_back(glm::vec4(side / 2, 0, 0.11f, 1));


		shapes[4] = new HapticShape("Line", posLine);
	}
}


void configureContent(PBD_PrimitiveManager_Handler pm, HapticShape* shape, int numPoints, int baseFrequency, int numSamples) {
	debugprintf("\n\nCurrent stimuli:\n\t -Input: %s, %f m, %d points, %d Hz (per point).", shape->name(), shape->length(), numPoints, baseFrequency);
	debugprintf("\n\t -devived parameters: draw speed = %f m/s; draw frequency = %d Hz .", shape->length() * baseFrequency, baseFrequency * numPoints);
	debugprintf("\n\t diameter(line length)=%f meters .", side1);


	//0. Disable previously existing primitives:
	std::list<cl_uint>::iterator p = primitives.begin();
	for (; p != primitives.end(); p++) {
		PBDEngine_CWrapper_setPrimitiveEnabled(pm, *p, false);
		PBDEngine_CWrapper_releasePrimitive(pm, *p);
	}
	primitives.clear();
	PBDEngine_CWrapper_commitUpdates(pm);


	//1. Destroy previous position descriptors:
	PBDEngine_CWrapper_releasePositionsDescriptor(pm, currentPD);
	//2. Sample new shape: We do not check 10000 % baseFrequency again.
	size_t updatesPerShape = 10000 / baseFrequency;
	if (numSamples < 1) numSamples = updatesPerShape;
	debugprintf("\n\t number of samples = %d", numSamples);
	debugprintf("\n\t updates per sample = %f\n\n", float(updatesPerShape) / numSamples);


	if (updatesPerShape < 1) {
		printf("\n ZERO UPDATES PER SHAPE, overriding to 1", numSamples);
		updatesPerShape = 1;
		if (numSamples < 1) numSamples = 1;
	}

	if (updatesPerShape < numSamples) {
		printf("\n NOT ENOUGH UPDATES FOR NUMBER OF SAMPLES, undersampling", numSamples);
	}


	float* samples = shape->discretiseShape(numSamples);

	float* bufferPerShape;
	if (updatesPerShape == numSamples)
		bufferPerShape = samples;
	else
	{
		bufferPerShape = new float[updatesPerShape * 4];
		for (int updateIndex = 0; updateIndex < updatesPerShape; updateIndex++)
		{
			float relativeIndex = float(updateIndex) / updatesPerShape;
			int sampleIndex = int(relativeIndex * numSamples);

			for (int i = 0; i < 4; i++)
				bufferPerShape[updateIndex * 4 + i] = samples[sampleIndex * 4 + i];
		}
	}

	currentPD = PBDEngine_CWrapper_createPositionsDescriptor(pm, bufferPerShape, updatesPerShape);
	//3. Create "numPoint" primitives, using these descriptors. 
	for (int p = 0; p < numPoints; p++) {
		cl_uint primitive = PBDEngine_CWrapper_declarePrimitive(pm, currentPD, fixedAmplitude, (p * updatesPerShape) / numPoints);
		PBDEngine_CWrapper_setPrimitiveEnabled(pm, primitive, true);
		primitives.push_back(primitive);
	}
	PBDEngine_CWrapper_commitUpdates(pm);
	if (updatesPerShape != numSamples) delete bufferPerShape;
	delete samples;
}

void destroyContent(PBD_PrimitiveManager_Handler pm) {
	//0. Disable previously existing primitives:
	std::list<cl_uint>::iterator p = primitives.begin();
	for (; p != primitives.end(); p++) {
		PBDEngine_CWrapper_setPrimitiveEnabled(pm, *p, false);
		PBDEngine_CWrapper_releasePrimitive(pm, *p);
	}
	primitives.clear();
	//1. Destroy previous position descriptors:
	PBDEngine_CWrapper_releasePositionsDescriptor(pm, currentPD);
	PBDEngine_CWrapper_releaseAmplitudesDescriptor(pm, fixedAmplitude);
	PBDEngine_CWrapper_commitUpdates(pm);

	//If you are using "force sync", we need to give the engine a chance to apply all this
	// Calling update_HighLevel allows engine to react to changes 
	PBDEngine_CWrapper_update_HighLevel(pm, NULL, 0, NULL, NULL/*, GSPAT::MatrixAlignment::RowMajorAlignment*/);
	Sleep(100);
}