NDContentPage.OnToolTipsLoaded({34:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype34\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Add_Member(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It adds a new member to the club by writing into The <b>credentials</b> and <b>infos</b> databases.</div></div>",46:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype46\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Add_Film(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Owner</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div></div>",48:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype48\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Modify_Or_Delete_Film(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Delete_Modify,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>Film</b>&nbsp; Database:</div></div>",49:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype49\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Display_Film_By_Type(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used to display the Films by type :</div></div>",50:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype50\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Sign_In_Member(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It prompts The user to enter his/her login and password to sign in and compare the input to the actual database.</div></div>",51:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype51\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Modify_Or_Delete_Member(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Delete_Modify,</td></tr><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">This functions is used on Double mode especially to interact with the <b>member infos</b> and <b>Credentials</b> Databases:</div></div>",52:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype52\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">void</span> Member_Alpha_Display()</div><div class=\"TTSummary\">This functions is used to display the Members in alphabetical order :</div></div>",58:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype58\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Checking_Max_Borrows(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Member_category</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It checks if the max borrowed films for a specific member is attained by counting the number of films in the <b>Personal Borrowed films</b> database which basically the number of lines</div></div>",59:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype59\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> Borrow_Return_Film(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td></td><td class=\"PName last\">Borrow_Return,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS,</td></tr><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It\'s the core function for the borrow/return operation and it\'s used on Double mode especially to interact with the <b>Film</b> , <b>Personal Borrowed films</b> , <b>Global Borrowers</b> and <b>Global Borrowed films</b> Databases:</div></div>",60:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype60\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Switch_ADMIN_Borrowing_Menu(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">The switch Menu associated with the <b>ADMIN Borrowings</b> where he can :</div></div>",65:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype65\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Display_Personal_Borrowed_Films(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It displays all the Borrowed films by reading from the <b>Personal Borrowed films</b> Database.</div></div>",66:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype66\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Check_If_Borrows(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">char</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">Borrower</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It Checks if the memeber have already borrowed any film if the user try to return a film without borrowings.&nbsp; It simply just check if the <b>Personal Borrowed films</b> database exists.</div></div>",70:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype70\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Switch_Adherant_account_Menu(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">loggedout</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">The switch Menu associated with the <b>Adherant Account</b> where he can :</div></div>",71:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype71\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Switch_ADMIN_FILM_Menu(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">The switch Menu associated with the <b>ADMIN Films</b> where he can :</div></div>",72:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype72\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Switch_ADMIN_account_Menu(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">loggedout</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">The switch Menu associated with the <b>ADMIN Account</b> where he can :</div></div>",76:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype76\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">int</span> Switch_Adherant_Borrowing_Menu(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Borrowing_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">LOAN,</td></tr><tr><td class=\"PType first\">Film_Infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">FILM,</td></tr><tr><td class=\"PType first\">Member_credentials&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_CREDENTIALS,</td></tr><tr><td class=\"PType first\">Member_infos&nbsp;</td><td class=\"PNamePrefix\">*</td><td class=\"PName last\">ADHERANT_INFOS</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">The switch Menu associated with the <b>Adherant Borrowings</b> where he can :</div></div>",79:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype79\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> delay(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">int</span>&nbsp;</td><td class=\"PName last\">sec_numb</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">It freezes the computer screen in a certain amout of time</div></div>"});