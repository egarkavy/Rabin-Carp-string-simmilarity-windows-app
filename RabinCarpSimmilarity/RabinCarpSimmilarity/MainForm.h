#pragma once
#include "RabinCarp.h";
#include "FileReader.h";
#include <algorithm>;

namespace RabinCarpSimmilarity {

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
		RabinCarp ^rb;
		System::String ^mainString;
	private: System::Windows::Forms::Label^  IsEq;
	public:

	public:
		System::String ^patternString;

		MainForm(void)
		{
			InitializeComponent();
			//*patternString = readFile("Pattern.txt");

			mainString = readFile(gcnew String("Main.txt"));
			patternString = readFile(gcnew String("Pattern.txt"));

			rb = gcnew RabinCarp();
			
			mainString->ToCharArray();

			OriginalText->Text = mainString;
			Pattern->Text = patternString;
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
	private: System::Windows::Forms::Button^  Test;
	protected:

	private: System::Windows::Forms::CheckBox^  IgnoreCase;
	private: System::Windows::Forms::CheckBox^  IgnoreSeparationMarks;
	private: System::Windows::Forms::RichTextBox^  OriginalText;
	private: System::Windows::Forms::RichTextBox^  Pattern;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Test = (gcnew System::Windows::Forms::Button());
			this->IgnoreCase = (gcnew System::Windows::Forms::CheckBox());
			this->IgnoreSeparationMarks = (gcnew System::Windows::Forms::CheckBox());
			this->OriginalText = (gcnew System::Windows::Forms::RichTextBox());
			this->Pattern = (gcnew System::Windows::Forms::RichTextBox());
			this->IsEq = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Test
			// 
			this->Test->Location = System::Drawing::Point(295, 259);
			this->Test->Name = L"Test";
			this->Test->Size = System::Drawing::Size(75, 23);
			this->Test->TabIndex = 0;
			this->Test->Text = L"Проверить";
			this->Test->UseVisualStyleBackColor = true;
			this->Test->Click += gcnew System::EventHandler(this, &MainForm::Test_Click);
			// 
			// IgnoreCase
			// 
			this->IgnoreCase->AutoSize = true;
			this->IgnoreCase->Location = System::Drawing::Point(13, 13);
			this->IgnoreCase->Name = L"IgnoreCase";
			this->IgnoreCase->Size = System::Drawing::Size(149, 17);
			this->IgnoreCase->TabIndex = 1;
			this->IgnoreCase->Text = L"Игнорировать регистры";
			this->IgnoreCase->UseVisualStyleBackColor = true;
			// 
			// IgnoreSeparationMarks
			// 
			this->IgnoreSeparationMarks->AutoSize = true;
			this->IgnoreSeparationMarks->Location = System::Drawing::Point(12, 36);
			this->IgnoreSeparationMarks->Name = L"IgnoreSeparationMarks";
			this->IgnoreSeparationMarks->Size = System::Drawing::Size(194, 17);
			this->IgnoreSeparationMarks->TabIndex = 2;
			this->IgnoreSeparationMarks->Text = L"Игнорировать знаки препинания";
			this->IgnoreSeparationMarks->UseVisualStyleBackColor = true;
			// 
			// OriginalText
			// 
			this->OriginalText->Location = System::Drawing::Point(212, 13);
			this->OriginalText->Name = L"OriginalText";
			this->OriginalText->Size = System::Drawing::Size(464, 96);
			this->OriginalText->TabIndex = 3;
			this->OriginalText->Text = L"Hello from spain";
			this->OriginalText->TextChanged += gcnew System::EventHandler(this, &MainForm::OriginalText_TextChanged);
			// 
			// Pattern
			// 
			this->Pattern->Location = System::Drawing::Point(212, 115);
			this->Pattern->Name = L"Pattern";
			this->Pattern->Size = System::Drawing::Size(464, 96);
			this->Pattern->TabIndex = 4;
			this->Pattern->Text = L"";
			this->Pattern->TextChanged += gcnew System::EventHandler(this, &MainForm::Pattern_TextChanged);
			// 
			// IsEq
			// 
			this->IsEq->AutoSize = true;
			this->IsEq->Location = System::Drawing::Point(416, 218);
			this->IsEq->Name = L"IsEq";
			this->IsEq->Size = System::Drawing::Size(0, 13);
			this->IsEq->TabIndex = 5;
			this->IsEq->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 408);
			this->Controls->Add(this->IsEq);
			this->Controls->Add(this->Pattern);
			this->Controls->Add(this->OriginalText);
			this->Controls->Add(this->IgnoreSeparationMarks);
			this->Controls->Add(this->IgnoreCase);
			this->Controls->Add(this->Test);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void Test_Click(System::Object^  sender, System::EventArgs^  e) {
	char* copyArr;
	
	/*mainString->copy(copyArr, *mainString->begin(), 0);
	std::string mainCopy(copyArr);
	patternString->copy(copyArr, *patternString->begin(), 0);
	std::string patternCopy(copyArr);*/
	System::String ^mCopy = mainString;
	System::String ^pCopy = patternString;

	if (IgnoreCase->Checked) {
		mCopy = mCopy->ToLower();
		pCopy = pCopy->ToLower();

			/*std::transform(mainCopy.begin(), mainCopy.end(), mainCopy.begin(), ::tolower);
			std::transform(patternCopy.begin(), patternCopy.end(), patternCopy.begin(), ::tolower);*/
		}
	if (IgnoreSeparationMarks->Checked) {
		mCopy = replaceAllMarks(mCopy);
		pCopy = replaceAllMarks(pCopy);
		}

	int index = rb->simmilarity(mCopy, pCopy);
	if (index > -1) {
		IsEq->Text = "Строка совпала: индекс: " + index;
	}
	else {
		IsEq->Text = "Совпадений нет";
	}

	}

		 System::String^ replaceAllMarks(System::String ^str) {
			 str = str->Replace(".", "");
			 str = str->Replace(",", "");
			 str = str->Replace("!", "");
			 str = str->Replace("?", "");
			 str = str->Replace(":", "");
			 str = str->Replace(";", "");

			 return str;
		 }
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Pattern_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void OriginalText_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
