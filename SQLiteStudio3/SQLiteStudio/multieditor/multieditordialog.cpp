#include "multieditordialog.h"
#include "multieditor.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>

MultiEditorDialog::MultiEditorDialog(QWidget *parent) :
    QDialog(parent)
{
    multiEditor = new MultiEditor();

    QVBoxLayout* vbox = new QVBoxLayout();
    vbox->addWidget(multiEditor);
    setLayout(vbox);

    multiEditor->setReadOnly(false);

    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    buttonBox->addButton(QDialogButtonBox::Ok);
    buttonBox->addButton(QDialogButtonBox::Cancel);
    vbox->addWidget(buttonBox);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

MultiEditorDialog::~MultiEditorDialog()
{
    delete multiEditor;
}

void MultiEditorDialog::setValue(const QVariant& value)
{
    multiEditor->setValue(value);
}

QVariant MultiEditorDialog::getValue()
{
    return multiEditor->getValue();
}

void MultiEditorDialog::setDataType(const SqlQueryModelColumn::DataType& dataType)
{
    multiEditor->setDataType(dataType);
}

void MultiEditorDialog::setReadOnly(bool readOnly)
{
    multiEditor->setReadOnly(readOnly);
}
