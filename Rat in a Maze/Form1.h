#pragma once

#include "stack.h"
#include "ratinmaze.h"

ratInMaze rat;

namespace RatinaMaze {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RichTextBox^  maze;
	private: array<CheckBox^>^ blocks;
	private: System::Windows::Forms::Button^  start;
	private: System::Windows::Forms::Button^  next;
	private: System::Windows::Forms::Button^  newMaze;
	private: System::Windows::Forms::ComboBox^  timeType;
	private: System::Windows::Forms::NumericUpDown^  time;
	private: System::Windows::Forms::CheckBox^  stepsTimer;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;

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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->maze = (gcnew System::Windows::Forms::RichTextBox());
			this->start = (gcnew System::Windows::Forms::Button());
			this->next = (gcnew System::Windows::Forms::Button());
			this->newMaze = (gcnew System::Windows::Forms::Button());
			this->timeType = (gcnew System::Windows::Forms::ComboBox());
			this->time = (gcnew System::Windows::Forms::NumericUpDown());
			this->stepsTimer = (gcnew System::Windows::Forms::CheckBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->time))->BeginInit();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->maze);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(512, 349);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Rat in a Maze";
			// 
			// maze
			// 
			this->maze->BackColor = System::Drawing::SystemColors::Control;
			this->maze->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->maze->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->maze->Location = System::Drawing::Point(22, 29);
			this->maze->Name = L"maze";
			this->maze->ReadOnly = true;
			this->maze->Size = System::Drawing::Size(468, 307);
			this->maze->TabIndex = 1;
			this->maze->Text = L"";
			// 
			// start
			// 
			this->start->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->start->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->start->Location = System::Drawing::Point(416, 382);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(108, 30);
			this->start->TabIndex = 6;
			this->start->Text = L"Start";
			this->start->UseVisualStyleBackColor = true;
			this->start->Click += gcnew System::EventHandler(this, &Form1::start_Click);
			// 
			// next
			// 
			this->next->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->next->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->next->Location = System::Drawing::Point(416, 382);
			this->next->Name = L"next";
			this->next->Size = System::Drawing::Size(108, 30);
			this->next->TabIndex = 7;
			this->next->Text = L"Next >";
			this->next->UseVisualStyleBackColor = true;
			this->next->Click += gcnew System::EventHandler(this, &Form1::next_Click);
			// 
			// newMaze
			// 
			this->newMaze->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->newMaze->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->newMaze->Location = System::Drawing::Point(12, 382);
			this->newMaze->Name = L"newMaze";
			this->newMaze->Size = System::Drawing::Size(108, 30);
			this->newMaze->TabIndex = 8;
			this->newMaze->Text = L"New Maze";
			this->newMaze->UseVisualStyleBackColor = true;
			this->newMaze->Click += gcnew System::EventHandler(this, &Form1::newMaze_Click);
			// 
			// timeType
			// 
			this->timeType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->timeType->Enabled = false;
			this->timeType->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->timeType->FormattingEnabled = true;
			this->timeType->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Second(s)", L"Millisecond(s)"});
			this->timeType->Location = System::Drawing::Point(232, 384);
			this->timeType->Name = L"timeType";
			this->timeType->Size = System::Drawing::Size(121, 27);
			this->timeType->TabIndex = 11;
			this->timeType->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::timeType_SelectedIndexChanged);
			// 
			// time
			// 
			this->time->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->time->Enabled = false;
			this->time->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->time->Location = System::Drawing::Point(129, 384);
			this->time->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {25000, 0, 0, 0});
			this->time->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->time->Name = L"time";
			this->time->Size = System::Drawing::Size(97, 27);
			this->time->TabIndex = 10;
			this->time->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			// 
			// stepsTimer
			// 
			this->stepsTimer->AutoSize = true;
			this->stepsTimer->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->stepsTimer->Location = System::Drawing::Point(12, 386);
			this->stepsTimer->Name = L"stepsTimer";
			this->stepsTimer->Size = System::Drawing::Size(111, 23);
			this->stepsTimer->TabIndex = 9;
			this->stepsTimer->Text = L"Steps Timer";
			this->stepsTimer->UseVisualStyleBackColor = true;
			this->stepsTimer->CheckedChanged += gcnew System::EventHandler(this, &Form1::stepsTimer_CheckedChanged);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// Form1
			// 
			this->AcceptButton = this->start;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(536, 439);
			this->Controls->Add(this->newMaze);
			this->Controls->Add(this->timeType);
			this->Controls->Add(this->time);
			this->Controls->Add(this->stepsTimer);
			this->Controls->Add(this->next);
			this->Controls->Add(this->start);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Rat in a Maze";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->time))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			blocks = gcnew array<CheckBox^>(98);
			int dx = 108, dy = 43;

			for (int x = 0; x < 98; x++)
			{
				blocks[x] = gcnew CheckBox();
				blocks[x]->Parent = this;
				blocks[x]->AutoSize = true;
				blocks[x]->Location = System::Drawing::Point(dx, dy);
				blocks[x]->Size = System::Drawing::Size(15, 14);
				blocks[x]->Name = L"block" + x;
				blocks[x]->TabIndex = x + 2;
				blocks[x]->UseVisualStyleBackColor = true;
				dx += 40 + (x % 5) % 10;

				if ((x + 1) % 10 == 9) {
					dx = 65;
					dy += 29 + (x % 3);
				}
			}

			groupBox1->SendToBack();
			maze->Text = rat.display();
			next->Visible = false;
			newMaze->Visible  = false;
			timeType->SelectedIndex = 0;
		}

		private: System::Void start_Click(System::Object^  sender, System::EventArgs^  e) {
			for (int x = 0; x < 98; x++)
			{
				if (blocks[x]->Checked)
					rat.addBlock(((x + 1) / 10) % 10, (x + 1) % 10);
				blocks[x]->Checked = false;
				blocks[x]->Visible = false;
			}

			rat.start();
			maze->Text = rat.display();
			start->Visible = false;
			stepsTimer->Visible = false;
			time->Visible = false;
			timeType->Visible = false;
			newMaze->Visible  = true;
			newMaze->Text  = "Cancel";
			if (stepsTimer->Checked) {
				next->Visible = false;
				int t = Convert::ToInt32(time->Text);
				if (timeType->SelectedIndex == 0)
					t *= 1000;
				timer1->Interval = t;
				timer1->Enabled = true;
			} else {
				next->Visible = true;
				AcceptButton = next;
			}
		}

		private: System::Void stepsTimer_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			if (stepsTimer->Checked) {
				time->Enabled = true;
				timeType->Enabled = true;
			} else {
				time->Enabled = false;
				timeType->Enabled = false;
			}
		}

		private: System::Void timeType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			if (timeType->SelectedIndex == 0) {
				time->Minimum = 1;
				time->Text = System::Convert::ToString(System::Convert::ToInt32(time->Text) / 1000);
				time->Maximum = 250;
			} else {
				time->Maximum = 25000;
				time->Text = System::Convert::ToString(System::Convert::ToInt32(time->Text) * 1000);
				time->Minimum = 1;
			}
		}

		private: void nextStep() {
			if (rat.canMove('r')) {
				rat.move('r');
			} else if (rat.canMove('d')) {
				rat.move('d');
			} else if (rat.canMove('l')) {
				rat.move('l');
			} else if (rat.canMove('u')) {
				rat.move('u');
			} else {
				bool solved = rat.back();

				if (!solved) {
					next->Visible = false;
					timer1->Enabled = false;
					MessageBox::Show("Can't Move the Rat.. The maze is unsolved", "Rat in a Maze", MessageBoxButtons::OK, MessageBoxIcon::Stop);
					newMaze->Text  = "New Maze";
					AcceptButton = newMaze;
				}
			}

			maze->Text = rat.display();
			if (rat.done()) {
				next->Visible = false;
				timer1->Enabled = false;
				MessageBox::Show("The Rat has arrived to the Cheese :D", "Rat in a Maze", MessageBoxButtons::OK, MessageBoxIcon::Information);
				newMaze->Text  = "New Maze";
				AcceptButton = newMaze;
			}
		}

		private: System::Void next_Click(System::Object^  sender, System::EventArgs^  e) {
			nextStep();
		}

		private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			nextStep();
		}

		private: System::Void newMaze_Click(System::Object^  sender, System::EventArgs^  e) {
			if (timer1->Enabled)
				timer1->Stop();

			if (rat.done() || MessageBox::Show("Are you sure that you want cancel this maze?", "Rat in a Maze", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
				rat = ratInMaze();
				maze->Text = rat.display();

				for (int x = 0; x < 98; x++)
					blocks[x]->Visible = true;

				newMaze->Visible  = false;
				next->Visible = false;
				start->Visible = true;
				AcceptButton = start;
				stepsTimer->Visible = true;
				timer1->Enabled = false;
				time->Visible = true;
				timeType->Visible = true;
			} else {
				if (stepsTimer->Checked)
					timer1->Start();
			}
		}
	};
}
