NDSummary.OnToolTipsLoaded("File:Support_Functions.h",{37:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype37\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Credentials_Input(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">FILE&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">pFILE_DATABASE</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used to take a valid <b>credentials</b> input from the member:</div></div>",39:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype39\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Infos_Input(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used to take valid <b>infos</b> input from the member i.e: &quot;Firstname ,Adress , Phonenumber...&quot;</div></div>",40:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype40\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> CHECK_IF_LOGIN_TAKEN(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">FILE&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">pfile,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Login</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Search within the the <b>credentials</b> database to check if the Login exists already</div></div>",41:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype41\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> CHECK_IF_PASSWORD_IS_NON_VALID(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">password</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Take the password as a parameter and browse through it\'s characters to check if it fits the standard norms (6 char min ,only alphabets and numbers ....)</div></div>",42:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype42\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> HIDE_PASSWORD(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">password</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Takes a pointer to the password as user input to hide it by displaying asterisks \'*\'</div></div>",43:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype43\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Encrypt_Password(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">password</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Takes the password as a parameter and browse through it\'s characters by adding a random generated number to the ASCII value of the characters.&nbsp; The random number will be our Encryption key.</div></div>",44:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype44\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Decrypt_Password(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">password,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td></td><td class=\"PName last\">Encryption_Key</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Takes the password as a parameter and browse through it\'s characters by substracting The Encryption Key number from the ASCII value of the characters.</div></div>",45:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype45\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Film_Infos_Input(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\">FILE&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">pFILM_DATABASE</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used to take valid <b>Film infos</b> input from the member i.e: &quot;Title,Code ....&quot;</div></div>",47:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype47\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> CHECK_IF_FILM_EXISTS(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">FILE&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">pfile,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM_Title,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM_Code</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Search within the the <b>Film</b> database to check if the Film exists already</div></div>",38:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype38\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Display_Specific_Type_Film(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\">FILE&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">pFILE_DATABASE,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Film_Type</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Browse through the <b>Film</b> Database given a special type of film to display it afterwards</div></div>",54:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype54\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Update_Borrowing_Infos(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Borrow_Return,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS,</td></tr><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>Film</b> Database:</div></div>",61:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype61\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Customize_File(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Borrow_Return,</td></tr><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>Personal Borrowed films</b> Database:</div></div>",62:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype62\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Borrowers_Record(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Borrow_Return,</td></tr><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>Global Borrowers</b> Database:</div></div>",63:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype63\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> FILM_Record(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Borrow_Return,</td></tr><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>Global Borrowed films</b> Database:</div></div>"});