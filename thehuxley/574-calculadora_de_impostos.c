#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void roundit(double this) {
	int precision = round(this * 100);

	if (precision % 10 == 0) {
		printf("%.1lf\n", this);
	} else {
		printf("%.2lf\n", this);
	}

	return;
}

int main() {
	double taxa_importacao;
	taxa_importacao = 0.60;

	double cotacao_dolar, valor_produto, valor_frete, aliquota_icms;
	scanf("%lf %lf %lf %lf", &cotacao_dolar, &aliquota_icms, &valor_produto, &valor_frete);

	double valor_produto_reais, valor_frete_reais, valor_total_reais, valor_impostos_importacao, valor_icms, total_impostos, total_geral;

	valor_produto_reais = valor_produto * cotacao_dolar;
	valor_frete_reais = valor_frete * cotacao_dolar;
	
	if (valor_produto_reais >= 2500) {
		valor_total_reais = valor_produto_reais;
	} else {
		valor_total_reais = valor_produto_reais + valor_frete_reais;
	}
	
	valor_impostos_importacao = valor_total_reais * taxa_importacao;
	valor_icms = (valor_total_reais + valor_impostos_importacao) / (1 - (aliquota_icms / 100)) * aliquota_icms / 100;


	total_impostos = valor_impostos_importacao + valor_icms;
	total_geral = valor_total_reais + total_impostos;


	roundit(cotacao_dolar);
	roundit(valor_produto_reais);
	roundit(valor_frete_reais);
	roundit(valor_total_reais);
	roundit(valor_impostos_importacao);
	roundit(valor_icms);
	roundit(total_impostos);
	roundit(total_geral);
	if (valor_produto >= 2500) {
		printf("Impostos calculados sem o frete\n");
	} else {
		printf("Impostos calculados com o frete\n");
	}
}