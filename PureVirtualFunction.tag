<?xml version='1.0' encoding='UTF-8' standalone='yes' ?>
<tagfile>
  <compound kind="class">
    <name>AddContributoryDialog</name>
    <filename>d9/dfa/classAddContributoryDialog.html</filename>
    <member kind="function">
      <type></type>
      <name>AddContributoryDialog</name>
      <anchorfile>d9/dfa/classAddContributoryDialog.html</anchorfile>
      <anchor>a75ef0d55afcf2cc30a702bb4792ccc2b</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>AddProjectDialog</name>
    <filename>d0/d23/classAddProjectDialog.html</filename>
    <member kind="function">
      <type></type>
      <name>AddProjectDialog</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>abb96542ad074344f634d0ff834e65f03</anchor>
      <arglist>(int id=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>adb873176b67a671fc417e7ab21389c21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>d0/d23/classAddProjectDialog.html</anchorfile>
      <anchor>a3e6011001312acd234f2352f1a796f0e</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Billing</name>
    <filename>df/d81/classBilling.html</filename>
    <base>IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Billing</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a8e7a38f9ef550c20ce1bf6b46153defa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a3d96a6baed6ca2d2e1096496f0fd3270</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a8beb72061cd53a964cf0ba3f04686613</anchor>
      <arglist>(int getId)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>ab5efe0286d292707073b9f1cecd98d6f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QMap&lt; Project, QList&lt; Contributory &gt; &gt;</type>
      <name>getContributories</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a08416c71eee43ec294e666ce45d43856</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTitle</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>ad817d4a1dfa011d20b4358a896662f0e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTitle</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a3e5e98325bd0e9fb4c253ddf07bf66c8</anchor>
      <arglist>(const QString &amp;getTitle)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNumber</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a23a9446aef6af58bcfa698b76cc24731</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNumber</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a1178eab66407b0761c35a13d8da84cdb</anchor>
      <arglist>(int getNumber)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>isBilling</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>ad616bbb5664e0ba2bac6982f06a7c723</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setIsBilling</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>a81a3b85e0e051239521b4e3d93f297c2</anchor>
      <arglist>(bool isBilling)</arglist>
    </member>
    <member kind="function">
      <type>QDate</type>
      <name>getDate</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>ad3657e1cdf05613cfca4b22b62976213</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDate</name>
      <anchorfile>df/d81/classBilling.html</anchorfile>
      <anchor>ad1cb89772dc12335543ff7d422d18bd4</anchor>
      <arglist>(const QDate &amp;getDate)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getId</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>a61523b015ec148d4e68ee8054c2ad3e3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setId</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>ad4f47f3e25302c506ce98103e616ca57</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>_id</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>a49f0ca7727c7d12eb78f670c882a3028</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ComboBoxModelWidget</name>
    <filename>d5/d79/classComboBoxModelWidget.html</filename>
  </compound>
  <compound kind="class">
    <name>connexiondialog</name>
    <filename>dc/db6/classconnexiondialog.html</filename>
  </compound>
  <compound kind="class">
    <name>Contributory</name>
    <filename>d5/d09/classContributory.html</filename>
    <base>IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Contributory</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>a5991c01efd2dedcbbddde252c48d7af8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>a5c09902237bba780b594129dc2fa60d6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>a2b834e0288c93ba9ed70acf7a0b8c32d</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>a59641dbc35947c31eb841b46fed6130f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Project</type>
      <name>getProject</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>a181a6cd0d0f34d3f671e10aa24bf3a54</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setProject</name>
      <anchorfile>d5/d09/classContributory.html</anchorfile>
      <anchor>ab002e076bb131fab82e8a6a289b2d6ca</anchor>
      <arglist>(const Project &amp;id)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Customer</name>
    <filename>d9/d12/classCustomer.html</filename>
    <base>IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Customer</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>abcc8fae9701e5ba9d7d6fe44498b34e3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Customer</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>aaea8b3d534c411de73c4fadc26ae114c</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>adcc34b0b12a4d6bf4570f082fef63448</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>ac77f54786ea2bd4c1696c0a76301c639</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a8a091ee90fdd7f89a45b28d23c7b834f</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFirstnameReferent</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>afda5111886086587dea8b8101bf02fea</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFirstnameReferent</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>acffda49d2eaf0b0389daa74720887fae</anchor>
      <arglist>(const QString &amp;firstnameReferent)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getLastnameReferent</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a9232155d920aa83e90fcdae0f4b0f47c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLastnameReferent</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a77d5f5d1c7e6ebc5c1a67adf937f82c0</anchor>
      <arglist>(const QString &amp;lastnameReferent)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCompany</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>ae58412194bbc03439aa1bcd387afbe79</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCompany</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a9d13cc3ad8464df4211da10213821fcc</anchor>
      <arglist>(const QString &amp;company)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getAddress</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>af3e348865143342ad9c67981eb61e0c8</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAddress</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>addd0675e408a13f6ab95ec5bd5a3a13b</anchor>
      <arglist>(const QString &amp;address)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPostalCode</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a39073588f2d7669b12a8ecc33b3c4224</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPostalCode</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a3973123c0e94d876124cfdd0444acfd1</anchor>
      <arglist>(const QString &amp;postalCode)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCity</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a1eaf38d67a4ac9c8fcc675ff81f724ba</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCity</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a1fb29f507135a9f21b29e7799aec14f0</anchor>
      <arglist>(const QString &amp;city)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCountry</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a426126096db853802249e10506dc138c</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCountry</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a81545977d1de88b4ffd6f6b1356ea118</anchor>
      <arglist>(const QString &amp;country)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getEmail</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a6ab797361537bf4c8b35cce5f1562299</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmail</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a64b383efde5855bde7ef385c6f73e45d</anchor>
      <arglist>(const QString &amp;email)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getMobilePhone</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a08546759b1b1f046389bc6ab6b467149</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMobilePhone</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>aec562d504cd6c6e3db153544b102e028</anchor>
      <arglist>(const QString &amp;mobilePhone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPhone</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a20b37c158f138def2014f24f291f2aa0</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPhone</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a850d6e8e1a061362928de94553cb12a6</anchor>
      <arglist>(const QString &amp;phone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFax</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>ab982339f461136ce230740d776a98ae9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFax</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a29049b62abb6aa0733c5def198ed62e5</anchor>
      <arglist>(const QString &amp;fax)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator==</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>ae55c14b91c08ba15c9593a47931d1949</anchor>
      <arglist>(const Customer &amp;c)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>operator!=</name>
      <anchorfile>d9/d12/classCustomer.html</anchorfile>
      <anchor>a95057d943f370a75c0bfa3d9805b611c</anchor>
      <arglist>(const Customer &amp;c)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerContextualMenu</name>
    <filename>d5/db9/classCustomerContextualMenu.html</filename>
  </compound>
  <compound kind="class">
    <name>CustomerDatabase</name>
    <filename>dc/d7c/classCustomerDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getCustomersTable</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2e25b4f197ccbdd2c5753558dbe18d4b</anchor>
      <arglist>(QString filter=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getCustomersTree</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a0fc1ca7fe1020cef19b2423531c4e934</anchor>
      <arglist>(QString filter=&quot;&quot;)</arglist>
    </member>
    <member kind="function">
      <type>Customer *</type>
      <name>getCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>ae510e11ab1efe33b8e1da21bc1ca6f2d</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a522337809fe7588ddc8b5eb27b0cb640</anchor>
      <arglist>(const Customer &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2ae17af9bcbf889dec21b4acae3161e1</anchor>
      <arglist>(const Customer &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeCustomer</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>aa1d21765bdf6319e580b3fcf20d841d1</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbCustomers</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a1c60ecbaa2594426b522746c70beee19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>lastError</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a17465cc3fe0a8b853f96599e0584cc84</anchor>
      <arglist>(const QSqlQuery &amp;q)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>testCases</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a702ce00658c10518d2ddbbd234a0c67d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cleanDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a6c7ca19f0107fdad000c268fc2b14ac0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>executeFile</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a06216acb010c0ea93ac2a53aa46256c2</anchor>
      <arglist>(QString pName)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>openTransaction</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>ace56e75784477e79197485e9b5980804</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>closeTransaction</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a8322990bcba006d0d82ac069ad6e0307</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>close</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>ab89cb07242f0ab1d4058974bf3e7cf19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>open</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a0d0134e05c8f2dc4fcbbb2f36c02a779</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Database</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a84d399a2ad58d69daab9b05330e1316d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a8b03d7f4a92325b9e519fd3f8a2e245c</anchor>
      <arglist>(QSqlDatabase sql)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>createDatabase</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a2dc260583a49889bed8097e21953594e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static CustomerDatabase *</type>
      <name>instance</name>
      <anchorfile>dc/d7c/classCustomerDatabase.html</anchorfile>
      <anchor>a2b9546b1e5803c4055529d2a7f7df95e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Database *</type>
      <name>instance</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>aa334760d1e18f82a344fb696547bfa5c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Database</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a4703c80e6969d33565ea340f768fdadf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>QVariant</type>
      <name>value</name>
      <anchorfile>de/d03/classDatabase.html</anchorfile>
      <anchor>a88f0ccd102fc421fb10ddad0fd94e8c1</anchor>
      <arglist>(const QSqlQuery &amp;q, const QString &amp;champ)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>CustomerDataWidget</name>
    <filename>df/df4/classCustomerDataWidget.html</filename>
  </compound>
  <compound kind="class">
    <name>Database</name>
    <filename>de/d03/classDatabase.html</filename>
  </compound>
  <compound kind="class">
    <name>DbException</name>
    <filename>dd/dca/classDbException.html</filename>
    <member kind="function">
      <type></type>
      <name>DbException</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a22204317679895d999e3621cf97d5dee</anchor>
      <arglist>(const QString fct, const QString fctName, const QString logError, float errorCode)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~DbException</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a57b57d4d9010c06d158ccc44d45a1376</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>popupMessage</name>
      <anchorfile>dd/dca/classDbException.html</anchorfile>
      <anchor>a06765391cd11f596721c877c1a62c2f1</anchor>
      <arglist>(QWidget *parent)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DialogAddCustomer</name>
    <filename>df/d01/classDialogAddCustomer.html</filename>
    <member kind="function">
      <type></type>
      <name>DialogAddCustomer</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a6123adb32813c5ebe71ce06012c46b9c</anchor>
      <arglist>(int id=0, QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>ae06c708abccad5ce0b8523c94b40eb75</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a1492352d114740bb44178f2415555155</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>df/d01/classDialogAddCustomer.html</anchorfile>
      <anchor>a6affc8db156ee183ffd14a71d06a8534</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IDatabaseModel</name>
    <filename>d1/dc3/classIDatabaseModel.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>commit</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>a2d4fd70557c1815d100df17ba0751cbd</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>hydrat</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>a25e44ed10a75976f86e14d34aea02c37</anchor>
      <arglist>(int id)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>remove</name>
      <anchorfile>d1/dc3/classIDatabaseModel.html</anchorfile>
      <anchor>a11d94697daf0af2b44fbe37ef831ea94</anchor>
      <arglist>()=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Log</name>
    <filename>d0/d77/classLog.html</filename>
    <member kind="function">
      <type></type>
      <name>~Log</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>a0fbfda88fbee5027c89f6eb121059360</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>write</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>acef079f691840d7afd2ed9482d5d66ea</anchor>
      <arglist>(const QString text)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Log</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>af6071a60aa52b6c1b511f99b4bc1b8fe</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static Log &amp;</type>
      <name>instance</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>ad8ef93302c147f832ed8202a6b039eb5</anchor>
      <arglist>(TypeLog type=INFO)</arglist>
    </member>
    <member kind="friend">
      <type>friend Log &amp;</type>
      <name>operator&lt;&lt;</name>
      <anchorfile>d0/d77/classLog.html</anchorfile>
      <anchor>a1ecba3328cadecbbd7d65ae2852171fc</anchor>
      <arglist>(Log &amp;logger, const QString &amp;text)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MainWindow</name>
    <filename>d6/d1a/classMainWindow.html</filename>
    <member kind="slot">
      <type>void</type>
      <name>addCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a661e495fc5b587dce8c7b930120098aa</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>afff9ca5b1b867af6b54eb1c8d9501522</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>removeCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>adb6fcfe64c3a11f28655e397b3accea9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>openCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>ad2f2a4051df4fc4776ea4465cf6b6ecb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>editUser</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a32fb574dece506733a3b80d2ccf565ac</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>search</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>aa186e57f984c98ea0266536df32acebd</anchor>
      <arglist>(QString)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>search</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a274dd0e068ebdc2a752e7ef05209fb2d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>newProject</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a31a63c4615f9c26a6df6e8c3b52967a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutQt</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a4710d90108bd39f7b80bdc6c3a1b1aef</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutFact</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a82e1b6ba63283af94f37684cf14b5c66</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutFactDev</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>af9af9644d45d2af769d18f2370eed83e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>aboutIcons</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>ae6a7598b9931ca8901a62bb95c490e0e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="slot">
      <type>void</type>
      <name>changeCustomer</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>afa850634f7968a6e9803a25e905f3178</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MainWindow</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a8b244be8b7b7db1b08de2a2acb9409db</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getCurrentCustomerId</name>
      <anchorfile>d6/d1a/classMainWindow.html</anchorfile>
      <anchor>a0584b17eb78c07b513524a09bd914042</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Parameters</name>
    <filename>de/d0a/classParameters.html</filename>
    <member kind="variable" static="yes">
      <type>static const QString</type>
      <name>DB_FILENAME</name>
      <anchorfile>de/d0a/classParameters.html</anchorfile>
      <anchor>a80b98bd51d910bcc2203afcacbc7df87</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>static const double</type>
      <name>VERSION</name>
      <anchorfile>de/d0a/classParameters.html</anchorfile>
      <anchor>a279ee24140c761de46178daa8960bdc8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Popup</name>
    <filename>d7/d6b/classPopup.html</filename>
  </compound>
  <compound kind="class">
    <name>Project</name>
    <filename>db/d91/classProject.html</filename>
    <base>IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>Project</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>aa007ecd17d5bc800e7a956cf666eea21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Project</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a8f608fdf1f0687598294f9534d702dd5</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>ab471d9354fb128c801f455e9a6bef675</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>aa966f15c9c8a277844a75c3530701525</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a7bd735a59c2fdf2718db14c3073245fc</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getName</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>af547be6d3433bbf4ccf0f905788a9fee</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setName</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>ab330ed5176b1eb93b558676fff8c47e1</anchor>
      <arglist>(const QString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getDescription</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>ae7cc47cfca8038bf63b67f0d255e92dd</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDescription</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a08632a8a8905245559c844c863fc796b</anchor>
      <arglist>(const QString &amp;description)</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>getDailyRate</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a1f34916428682e0134675d45f93a2173</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setDailyRate</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>aa3c6dc9722ed16fd69a6034b2398a7c9</anchor>
      <arglist>(double dailyRate)</arglist>
    </member>
    <member kind="function">
      <type>Customer *</type>
      <name>getCustomer</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a92b286f48db8f3643214e0c802201d1e</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCustomer</name>
      <anchorfile>db/d91/classProject.html</anchorfile>
      <anchor>a0f1d520c0ecbbfa286d310d18c55dabd</anchor>
      <arglist>(Customer *customer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ProjectDatabase</name>
    <filename>d4/d8d/classProjectDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>Project *</type>
      <name>getProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a895c03003dc4deea0bc429776337795f</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>addProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a3e2c3d198f7f5724ae0388fd49f4e8cb</anchor>
      <arglist>(const Project &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a959b2f9617969277a8c92a8239c613f1</anchor>
      <arglist>(const Project &amp;)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>removeProject</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a52f3c3b312c418568531eb4cd2ecf615</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbProjects</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a48ab28fa18bc3f0371f8c17c5421a46e</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNbProjectsForACustomer</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a3dbf2e270674727fc479d392c6609dec</anchor>
      <arglist>(const int pId)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static ProjectDatabase *</type>
      <name>instance</name>
      <anchorfile>d4/d8d/classProjectDatabase.html</anchorfile>
      <anchor>a06a93b599475687f19f66c7bbb921899</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ProjectsWidget</name>
    <filename>de/da7/classProjectsWidget.html</filename>
  </compound>
  <compound kind="class">
    <name>RateWidget</name>
    <filename>dc/da5/classRateWidget.html</filename>
  </compound>
  <compound kind="class">
    <name>Search</name>
    <filename>de/dd3/classSearch.html</filename>
    <member kind="function">
      <type></type>
      <name>Search</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>af629e7254d367d2b2cacfb0699c9de31</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Search</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>afd7e16f7369d7a44189e530292b5faa0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFilter</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>ad4cbed03998957eb80a2d1b536407f01</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getSearchInCompanies</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a683100feb68358d1eedda781f700cd46</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSearchInCompanies</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a1c2abc83b8995d5b1d908905a7212042</anchor>
      <arglist>(bool getSearchInCompanies)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getSearchInReferentLastname</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>afb76798798f03d34f8d2363d7062ec0f</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSearchInReferentLastname</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a18603321d8e2039b181dbfe082689a08</anchor>
      <arglist>(bool getSearchInReferentLastname)</arglist>
    </member>
    <member kind="function">
      <type>bool</type>
      <name>getGroupFilter</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a19db0f8c76c414514b9df09e07b4d962</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setGroupFilter</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a8a944b2ece0cafe967afb4334d92b62a</anchor>
      <arglist>(bool getGroupFilter)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getText</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a10a8f699332477cab0d512027bdaaa44</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setText</name>
      <anchorfile>de/dd3/classSearch.html</anchorfile>
      <anchor>a92f09448baccf5cddbc433835b716b36</anchor>
      <arglist>(const QString &amp;getText)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>searchWidget</name>
    <filename>d2/dfd/classsearchWidget.html</filename>
    <member kind="function">
      <type>int</type>
      <name>getCurrentCustomerId</name>
      <anchorfile>d2/dfd/classsearchWidget.html</anchorfile>
      <anchor>ac74ae97eb8c147c89edc3dec3decf174</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>User</name>
    <filename>d9/dc0/classUser.html</filename>
    <base>IDatabaseModel</base>
    <member kind="function">
      <type></type>
      <name>User</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a4a0137053e591fbb79d9057dd7d2283d</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>User</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a6e84637389bc36a13300df82a7387bb0</anchor>
      <arglist>(int id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>commit</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>aee39916633f5bf89100a4a917b2db4a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>hydrat</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a2e4160755d2189979b758929e832b12c</anchor>
      <arglist>(int id=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>aba787de7188a5c7bc4b99734b1b093cf</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getFirstname</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>acad034d3a093164f056d06d9a3ee33a2</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setFirstname</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>ad9f69006800232eb19146d2354910412</anchor>
      <arglist>(const QString &amp;firstname)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getLastname</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>aabbb05d0c6e6be5ed078ba3c730b24b3</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLastname</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a90d5bae75aa56253642386ad42da171d</anchor>
      <arglist>(const QString &amp;lastname)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCompany</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>ace35ae55a1681e5df796ebee79fa5b07</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCompany</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a3a92e61c3e31dddeff27bc8c2307f2db</anchor>
      <arglist>(const QString &amp;company)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getTitle</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a44af1366445fb0284411f92d37231f2d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setTitle</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>ae51847b13715ba1fed59a2778397691a</anchor>
      <arglist>(const QString &amp;title)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getAddress</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>af5cebeb07ba0ebffb916f1f6fd7c002d</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAddress</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a14a70021648f51900cc54f6535d3a603</anchor>
      <arglist>(const QString &amp;address)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPostalCode</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a6a3ecafe2c72860cbc2cfc031d6112c9</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPostalCode</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>af53e170c1701dd1f275589d115f88076</anchor>
      <arglist>(const QString &amp;postalCode)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getCity</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a78a95519c1fb5ac91152ad231aac1484</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setCity</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a3e350353440e6a22e91c3f78a9a32a4f</anchor>
      <arglist>(const QString &amp;city)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getEmail</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>ae398ada63774cb0c91544637fdd415d1</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setEmail</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a13c5e816e990508b469096580884ce98</anchor>
      <arglist>(const QString &amp;email)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getMobilePhone</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a858eff50cbc71969bc5dd5e80045d342</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setMobilePhone</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a8d7afdfc9bcf32b00c20d1d70ae9cbb7</anchor>
      <arglist>(const QString &amp;mobilePhone)</arglist>
    </member>
    <member kind="function">
      <type>QString</type>
      <name>getPhone</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a5408061a1ba87e3d56a51490464d1149</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPhone</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a271e4179b9da5b409f98656b04431689</anchor>
      <arglist>(const QString &amp;phone)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getNoSiret</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a721f64ecb20c42c12ca87815ffb0a274</anchor>
      <arglist>() const </arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setNoSiret</name>
      <anchorfile>d9/dc0/classUser.html</anchorfile>
      <anchor>a9e77d4724778cfe4f0a6fda75d3b7c52</anchor>
      <arglist>(int noSiret)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>UserDatabase</name>
    <filename>de/d47/classUserDatabase.html</filename>
    <base>Database</base>
    <member kind="function">
      <type>QStandardItemModel *</type>
      <name>getUserTable</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>a6020d6686916f20b3e6a1a5fa5fa7978</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>User *</type>
      <name>getUser</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>ab95ed012ce83d09e57ad902cc304585c</anchor>
      <arglist>(const int pId=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateUser</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>a5d7ecaa321c764615ed3cff211ccd84f</anchor>
      <arglist>(const User &amp;)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>static UserDatabase *</type>
      <name>instance</name>
      <anchorfile>de/d47/classUserDatabase.html</anchorfile>
      <anchor>aa1ce356d9f6f903c786e5f623dac90b6</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>UserDataDialog</name>
    <filename>de/d9c/classUserDataDialog.html</filename>
    <member kind="function">
      <type></type>
      <name>UserDataDialog</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a51210d5e027d49b019fcd565d5b20e06</anchor>
      <arglist>(QWidget *parent=0)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>fillFields</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a22f266169243757212ba7eb61d083ddb</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>accept</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>ad6ba344db1a10b804ca8f5f9a6ffed2c</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reject</name>
      <anchorfile>de/d9c/classUserDataDialog.html</anchorfile>
      <anchor>a54519d6441212d50849de7b72ac5e623</anchor>
      <arglist>()</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>Utils</name>
    <filename>dc/dc5/classUtils.html</filename>
  </compound>
  <compound kind="dir">
    <name>src/database</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/database/</path>
    <filename>dir_803ee67260c130b45d29089798491ab2.html</filename>
    <file>customerdatabase.cpp</file>
    <file>customerdatabase.h</file>
    <file>database.cpp</file>
    <file>database.h</file>
    <file>projectdatabase.cpp</file>
    <file>projectdatabase.h</file>
    <file>userdatabase.cpp</file>
    <file>userdatabase.h</file>
  </compound>
  <compound kind="dir">
    <name>src/dialogs</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/dialogs/</path>
    <filename>dir_9870864803860a03def48f6710b1f137.html</filename>
    <file>addcontributorydialog.cpp</file>
    <file>addcontributorydialog.h</file>
    <file>addprojectdialog.cpp</file>
    <file>addprojectdialog.h</file>
    <file>dialogaddcustomer.cpp</file>
    <file>dialogaddcustomer.h</file>
    <file>userdatadialog.cpp</file>
    <file>userdatadialog.h</file>
  </compound>
  <compound kind="dir">
    <name>src/exceptions</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/exceptions/</path>
    <filename>dir_6e33d6500a76933db4361f663e54ab12.html</filename>
    <file>dbexception.cpp</file>
    <file>dbexception.h</file>
  </compound>
  <compound kind="dir">
    <name>src/models</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/models/</path>
    <filename>dir_bdeba5f06b852fec80257c0bf4c3c36e.html</filename>
    <file>billing.cpp</file>
    <file>billing.h</file>
    <file>contributory.cpp</file>
    <file>contributory.h</file>
    <file>customer.cpp</file>
    <file>customer.h</file>
    <file>idatabasemodel.h</file>
    <file>project.cpp</file>
    <file>project.h</file>
    <file>search.cpp</file>
    <file>search.h</file>
    <file>user.cpp</file>
    <file>user.h</file>
  </compound>
  <compound kind="dir">
    <name>src</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/</path>
    <filename>dir_68267d1309a1af8e8297ef4c3efbcdba.html</filename>
    <dir>src/database</dir>
    <dir>src/dialogs</dir>
    <dir>src/exceptions</dir>
    <dir>src/models</dir>
    <dir>src/widgets</dir>
    <file>connexiondialog.cpp</file>
    <file>connexiondialog.h</file>
    <file>log.cpp</file>
    <file>log.h</file>
    <file>mainwindow.cpp</file>
    <file>mainwindow.h</file>
    <file>parameters.cpp</file>
    <file>parameters.h</file>
    <file>utils.cpp</file>
    <file>utils.h</file>
  </compound>
  <compound kind="dir">
    <name>src/widgets</name>
    <path>/home/aroquemaurel/projets/qt/Fact/FactDev/src/widgets/</path>
    <filename>dir_0abdee562046be6f5823d1ca8c3fd13c.html</filename>
    <file>comboboxmodelwidget.cpp</file>
    <file>comboboxmodelwidget.h</file>
    <file>customercontextualmenu.cpp</file>
    <file>customercontextualmenu.h</file>
    <file>customerdatawidget.cpp</file>
    <file>customerdatawidget.h</file>
    <file>popup.cpp</file>
    <file>popup.h</file>
    <file>projectswidget.cpp</file>
    <file>projectswidget.h</file>
    <file>ratewidget.cpp</file>
    <file>ratewidget.h</file>
    <file>searchwidget.cpp</file>
    <file>searchwidget.h</file>
  </compound>
</tagfile>
