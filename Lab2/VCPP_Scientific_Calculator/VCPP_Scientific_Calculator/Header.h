#pragma once
double iFirstnum;
double iSecondnum;
double iResult;
double a;
String^ iOperator;
char iOperation;


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		MyForm::Width = 353;
		MyForm::Height = 473;
		txtDisplay->Width = 286;
		historyToolStripMenuItem1->Visible = false;
	}
private: System::Void historyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (historyToolStripMenuItem->Checked == true)
	{
		listBox1->Visible = true;
		historyToolStripMenuItem->Visible = false;
		historyToolStripMenuItem1->Visible = true;
		MyForm::Height = 632;
	}
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	Application::Exit();
}
private: System::Void scientificToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm::Width = 559;
	txtDisplay->Width = 487;
}
private: System::Void standardToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm::Width = 353;
	MyForm::Height = 473;
	txtDisplay->Width = 286;
}
private: System::Void button_Click(System::Object^  sender, System::EventArgs^  e) {
	//Buttons numbers
	Button ^ Numbers = safe_cast<Button^>(sender);
	if (txtDisplay->Text == "0")
	{
		txtDisplay->Text = Numbers->Text;
	}
	else
	{
		txtDisplay->Text = txtDisplay->Text + Numbers->Text;
	}
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//CE button
	txtDisplay->Clear();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// C button
	txtDisplay->Clear();
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	//Decimal point
	if (!txtDisplay->Text->Contains(","))
	{
		txtDisplay->Text = txtDisplay->Text + ",";
	}

}
private: System::Void Arithmetic_Op(System::Object^  sender, System::EventArgs^  e) {
	//Operators
	Button ^ op = safe_cast<Button^>(sender);
	iFirstnum = Double::Parse(txtDisplay->Text);
	txtDisplay->Text = "";
	//txtDisplay->Text += "";
	iOperator = op->Text;
	lblShowOp->Text = System::Convert::ToString(iFirstnum) + " " + iOperator;

}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//plus-minus
	if (txtDisplay->Text->Contains("-"))
	{
		txtDisplay->Text = txtDisplay->Text->Remove(0, 1);
	}
	else
	{
		txtDisplay->Text = "-" + txtDisplay->Text;
	}

}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	//egal
	//lblShowOp->Text = "";
	iSecondnum = Double::Parse(txtDisplay->Text);
	if (iOperator == "+")
	{
		iResult = iFirstnum + iSecondnum;
		txtDisplay->Text = System::Convert::ToString(iResult);
		listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	}
	else if (iOperator == "-")
	{
		iResult = iFirstnum - iSecondnum;
		txtDisplay->Text = System::Convert::ToString(iResult);
		listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	}
	else if (iOperator == "*")
	{
		iResult = iFirstnum * iSecondnum;
		txtDisplay->Text = System::Convert::ToString(iResult);
		listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	}
	else if (iOperator == "/")
	{
		iResult = iFirstnum / iSecondnum;
		txtDisplay->Text = System::Convert::ToString(iResult);
		listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	}
	else if (iOperator == "^")
	{
		txtDisplay->Text = System::Convert::ToString(Math::Pow(iFirstnum, iSecondnum));
		listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	}
}
private: System::Void historyToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
	historyToolStripMenuItem->Visible = true;
	listBox1->Width = 265;
	listBox1->Visible = false;
	MyForm::Height = 473;
	historyToolStripMenuItem1->Visible = false;
}
private: System::Void btn7_Click(System::Object^  sender, System::EventArgs^  e) {
	//Backspace
	if (txtDisplay->Text->Length > 0)
	{
		txtDisplay->Text = txtDisplay->Text->Remove(txtDisplay->Text->Length - 1, 1);
	}
}
private: System::Void button29_Click(System::Object^  sender, System::EventArgs^  e) {
	//Pi
	txtDisplay->Text = ("3,14159265358997632384626433832795");
}
private: System::Void button24_Click(System::Object^  sender, System::EventArgs^  e) {
	//Log
	a = Double::Parse(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString("log" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	a = Math::Log(a);
	txtDisplay->Text = System::Convert::ToString(a);
}
private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
	//Radical
	a = Double::Parse(txtDisplay->Text);
	a = Math::Sqrt(a);
	lblShowOp->Text = System::Convert::ToString("Sqrt" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	txtDisplay->Text = System::Convert::ToString(a);


}
private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
	//Sinus
	a = Double::Parse(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString("sin" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	a = Math::Sin(a);
	txtDisplay->Text = System::Convert::ToString(a);
}
private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
	//cosinus
	a = Double::Parse(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString("cos" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	a = Math::Cos(a);
	txtDisplay->Text = System::Convert::ToString(a);
}
private: System::Void button23_Click(System::Object^  sender, System::EventArgs^  e) {
	//tangent
	a = Double::Parse(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString("tan" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	a = Math::Tan(a);
	txtDisplay->Text = System::Convert::ToString(a);
}
private: System::Void button28_Click(System::Object^  sender, System::EventArgs^  e) {
	//x^2
	a = Convert::ToDouble(txtDisplay->Text) * Convert::ToDouble(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString((txtDisplay->Text) + "^" + "2");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	txtDisplay->Text = Convert::ToString(a);
}
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
	//1/x
	a = Convert::ToDouble(1.0 / Convert::ToDouble(txtDisplay->Text));
	lblShowOp->Text = System::Convert::ToString("1" + "/" + (txtDisplay->Text));
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	txtDisplay->Text = Convert::ToString(a);
}
private: System::Void button22_Click(System::Object^  sender, System::EventArgs^  e) {
	//lg x
	a = Double::Parse(txtDisplay->Text);
	lblShowOp->Text = System::Convert::ToString("lg" + "(" + (txtDisplay->Text) + ")");
	listBox1->Items->Add(System::Convert::ToString(lblShowOp->Text));
	a = Math::Log10(a);
	txtDisplay->Text = System::Convert::ToString(a);
}

	    // Boolean flag used to determine when a character other than a number is entered.
	    bool nonNumberEntered;

	    // Handle the KeyDown event to determine the type of character entered into the control.
private: System::Void key_down(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	// Initialize the flag to false.
	nonNumberEntered = false;

	// Determine whether the keystroke is a number from the top of the keyboard.
	if (e->KeyCode < Keys::D0 || e->KeyCode > Keys::D9)
	{
		// Determine whether the keystroke is a number from the keypad.
		if (e->KeyCode < Keys::NumPad0 || e->KeyCode > Keys::NumPad9)
		{
			// Determine whether the keystroke is a backspace.
			if (e->KeyCode != Keys::Back)
			{
				// A non-numerical keystroke was pressed.
				// Set the flag to true and evaluate in KeyPress event.
				nonNumberEntered = true;
			}
		}
	}
	if (e->KeyCode == Keys::D0 || e->KeyCode == Keys::NumPad0)
	{
		txtDisplay->Text += "0";
	}
	if (e->KeyCode == Keys::D1 || e->KeyCode == Keys::NumPad1)
	{
		txtDisplay->Text += "1";
	}
	if (e->KeyCode == Keys::D2 || e->KeyCode == Keys::NumPad2)
	{
		txtDisplay->Text += "2";
	}
	if (e->KeyCode == Keys::D3 || e->KeyCode == Keys::NumPad3)
	{
		txtDisplay->Text += "3";
	}
	if (e->KeyCode == Keys::D4 || e->KeyCode == Keys::NumPad4)
	{
		txtDisplay->Text += "4";
	}
	if (e->KeyCode == Keys::D5 || e->KeyCode == Keys::NumPad5)
	{
		txtDisplay->Text += "5";
	}
	if (e->KeyCode == Keys::D6 || e->KeyCode == Keys::NumPad6)
	{
		txtDisplay->Text += "6";
	}
	if (e->KeyCode == Keys::D7 || e->KeyCode == Keys::NumPad7)
	{
		txtDisplay->Text += "7";
	}
	if (e->KeyCode == Keys::D8 || e->KeyCode == Keys::NumPad8)
	{
		txtDisplay->Text += "8";
	}
	if (e->KeyCode == Keys::D9 || e->KeyCode == Keys::NumPad9)
	{
		txtDisplay->Text += "9";
	}
	if (e->KeyCode == Keys::Oemcomma)
	{
		txtDisplay->Text += ",";
	}
	if (e->KeyCode == Keys::OemMinus || e->KeyCode == Keys::Subtract)
	{
		txtDisplay->Text += "-";
	}

}
	    // This event occurs after the KeyDown event and can be used to prevent
	    // characters from entering the control.
private: System::Void key_press(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	// Check for the flag being set in the KeyDown event.
	if (nonNumberEntered == true)
	{
		// Stop the character from being entered into the control since it is non-numerical.
		e->Handled = true;
	}
}
};
}

